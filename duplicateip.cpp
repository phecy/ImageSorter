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

#define MATCHER_THRESHOLD .6 // from ipmatch.cc
#define MAX_IPS 50

using namespace vw;
using namespace vw::ip;

DuplicateIp::DuplicateIp(DuplicateRater* rater)
{
    this->rater = rater;
}

void DuplicateIp::addImage(VImage* vim) {
    DiskImageView<PixelGray<float> > im(vim->getFilename());

    HarrisInterestOperator interest_op;
    ScaledInterestPointDetector<HarrisInterestOperator> detector(interest_op);
    InterestPointList ips = detect_interest_points(im, detector);

    PatchDescriptorGenerator gen;
    gen(im, ips);

    vim->setIp(ips);
}

void DuplicateIp::rankOne(VImage* one, VImage* two) {
    vector<InterestPoint> ip1vec, ip2vec;
    InterestPointList ip1list = one->getIps();
    InterestPointList ip2list = two->getIps();

    InterestPointList::iterator iter = ip1list.begin();
    for(; iter != ip1list.end(); ++iter) ip1vec.push_back(*iter);
    iter = ip2list.begin();
    for(; iter != ip2list.end(); ++iter) ip2vec.push_back(*iter);

    vector<InterestPoint> matched_ip1, matched_ip2;

    // Run interest point matcher that uses KDTree algorithm.
    InterestPointMatcherSimple<L2NormMetric,NullConstraint> matcher(MATCHER_THRESHOLD);
    matcher(ip1vec, ip2vec, matched_ip1, matched_ip2);

    int rank = matched_ip1.size();

    // remove_duplicates(matched_ip1, matched_ip2);
    rater->addRanking(one->getQImage(), two->getQImage(),
                       rank, DuplicateRater::DUPLICATE_IP);

    //matcher(onelist.front().interest, twolist.front().interest, match1, match2);
    qDebug("DuplicateIP: Match1 size=%d, Match2 size=%d",
           matched_ip1.size(), matched_ip2.size());
}
