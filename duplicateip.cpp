#include <iostream>

#include "vw/Core.h"
#include "vw/InterestPoint.h"
#include "vw/InterestPoint/Matcher.h"
#include "vw/Image.h"
#include "vw/FileIO.h"

#include "duplicateip.h"
#include "duplicaterater.h"
#include "vimage.h"

#include <stdint.h>

#include "boundingBoxPresets.h"

#define MATCHER_THRESHOLD .6 // from ipmatch.cc
#define MAX_IPS 50

#define IP_LENIENCY 600 // more = less strict

using namespace vw;
using namespace vw::ip;

DuplicateIp::DuplicateIp(DuplicateRater* rater)
{
    this->rater = rater;
    foregroundDetect = new BoundingBox();
}

void DuplicateIp::addImage(VImage* vim) {
    /* boundingBox.h presets
    boundingBox fgBox = loadBox(vim);
    if(fgBox.first.first != -1) {
        vim->setForeground(fgBox);
        return;
    }*/

    // Saved ip filename
    string fn_ip = vim->getIpFullpath();

    // Check if found ips yet
    ifstream ifile(fn_ip.c_str());
    if (ifile) {
        vim->setIp(read_binary_ip_file(fn_ip));
    } else {
        // Find and write
        DiskImageView<PixelGray<float> > im(vim->getFullpath());

        HarrisInterestOperator interest_op(1e-9, .15);
        ScaledInterestPointDetector<HarrisInterestOperator> detector(interest_op);
        InterestPointList ips = detect_interest_points(im, detector);

        SGrad2DescriptorGenerator descriptor;
        descriptor(im, ips);

        write_binary_ip_file(fn_ip, ips);

        // Convert to vector
        vector<InterestPoint> ip_vec;
        for(InterestPointList::iterator i = ips.begin();
                                       i != ips.end(); ++i) {
            ip_vec.push_back(*i);
        }

        vim->setIp(ip_vec);
    }

    findForeground(vim);
}

void DuplicateIp::findForeground(VImage* vim) {
    // Find bounding box
    boundingBox fgBox = foregroundDetect->getBoundingBox(vim);
    vim->setForeground(fgBox);

    qDebug("else if(strcmp(vim->getFilename(), \"%s\") == 0)\n"
           "      fgBox = boundingBox(point(%d,%d),point(%d,%d));",
           vim->getFilename(), fgBox.first.first,fgBox.first.second,fgBox.second.first,fgBox.second.second);

    // Debug output
    foregroundDetect->debugPrint(vim, fgBox.first, fgBox.second);
    foregroundDetect->show();
}

void DuplicateIp::rankOne(VImage* one, VImage* two) {
    // Make filename
    string matched_fn = one->getFullpath();
    matched_fn.append("_");
    matched_fn.append(two->getFilename());
    matched_fn.append(".ipmatch");

    // Ip lists: all + matched
    vector<InterestPoint> ip1_vec = one->getIps();
    vector<InterestPoint> ip2_vec = two->getIps();
    vector<InterestPoint> matched_ip1, matched_ip2;

    // Check if matched ips yet
    ifstream ifile(matched_fn.c_str());
    if (ifile) {
        read_binary_match_file(matched_fn, matched_ip1, matched_ip2);
    } else {
        // Find and write
        InterestPointMatcherSimple<L2NormMetric,NullConstraint> matcher;
        matcher(ip1_vec, ip2_vec, matched_ip1, matched_ip2);

        write_binary_match_file(matched_fn, matched_ip1, matched_ip2);
    }

    // See how many matches compared to total ips
                // +1 --> sloppy div-0 prevention
    int rating = matched_ip1.size() * IP_LENIENCY
                / (ip1_vec.size()+ip2_vec.size()+1);

    qDebug("Img %d and %d have %d common ips --> %d rank", one->getIndex()+1,
            two->getIndex()+1, matched_ip1.size(), rating);

    rating = min(rating, 10);

    rater->addRanking(one, two, rating, DuplicateRater::DUPLICATE_IP);
}
