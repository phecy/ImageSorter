/*
This class is a wrapper which helps combine a
QImage and a VImage (Vision Workbench image)
*/

#ifndef VIMAGE_H
#define VIMAGE_H

#include <cstdlib>
#include <stdint.h>

#include <QMainWindow>
#include <QImage>

#include "exifinfo.h"
#include "util/common.h"

#define HNUMCOLORS 4
#define HBLACK 0
#define HRED 1
#define HGREEN 2
#define HBLUE 3

using namespace std;

typedef pair<int,int> Point;
typedef vector<float> HistogramChannel;
typedef vector<HistogramChannel> HistogramSet;

/*DEBUG class QMainWindow;*/
class VImage/*DEBUG : public QMainWindow*/
{
public:
    VImage(char* filename);
    ~VImage();

    // Data
    QImage* getQImage() { return qimage; }
    QImage* getQImage() const { return qimage; }
    uchar* getUchar() {return qimage->bits(); }

    // Information
    char* getFilename() { return filename; }
    char* getFullpath() { return fullpath; }
    int getIndex () const { return index; }
    void setIndex(int i) { index=i; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getOrigWidth() const { return origwidth; }
    int getOrigHeight() const { return origheight; }
    ExifInfo& getExif() { return exifdata; }
    void setExif(ExifInfo e) { exifdata = e; }

    // Rating
    void setUniqueness(float u) { uniqueness=u; }
    float getUniqueness() const { return uniqueness; }
    void setTotalQuality(float r) { quality=r; }
    float getTotalQuality() const { return quality; }
    void setQualities(vector<pair<string, float> > q) { qualitiesVec=q; }
    void setQuality(string attributeName, double value);
    const vector<pair<string, float> >& getQualities() { return qualitiesVec; }

    // For sharpdetect and duplicategaussian
    // Returns avg pixel difference
    static QImage gaussianFilter(const QImage& im, float strength);
    static int avgPixelDiff(const QImage& one, const QImage& two);

    // Colors
    // Make histogram starting at QImage's (x,y)
    static HistogramSet makeHistograms
                    (VImage* vim, int x, int y, int width, int height);
    const HistogramSet& getHistogram() const { return histograms; }
    HistogramChannel getHistogramK() { return histograms[HBLACK]; }
    HistogramChannel getHistogramR() { return histograms[HRED]; }
    HistogramChannel getHistogramG() { return histograms[HGREEN]; }
    HistogramChannel getHistogramB() { return histograms[HBLUE]; }
    const vector<int>& getMedians() { return medianColors; }
    const vector<int> getMedians() const { return medianColors; }
    int getMedGray() { return medianColors[HBLACK]; }
    int getMedRed() { return medianColors[HRED]; }
    int getMedGreen() { return medianColors[HGREEN]; }
    int getMedBlue() { return medianColors[HBLUE]; }
    const vector<int>& getAvgs() { return avgColors; }
    int getAvgGray() { return avgColors[HBLACK]; }
    int getAvgRed() { return avgColors[HRED]; }
    int getAvgGreen() { return avgColors[HGREEN]; }
    int getAvgBlue() { return avgColors[HBLUE]; }

private:
    void makeQImage();
    void makeMedianAndAvgColors();

    // Data
    QImage* qimage; // Scaled to 800px wide

    // Information
    char* filename;
    char* fullpath; // including filename
    string ip_fullpath;
    int index; // As sorted by filesystem
    int width, height; // Width scaled to 800px
    int origwidth, origheight; // Original qimage width+height
    ExifInfo exifdata;

    // The image's final rank (combination of the qualities vector)
    float quality; 
    // The image's final uniqueness, dependenent on its sorted position
    float uniqueness; 

    // A name and rating for each item in the quality vector
    vector<pair<string, float> > qualitiesVec;

    // A name and rating for each item in the uniqueness vector
    vector<pair<string, float> > uniquenessVec;

    // Colors
    HistogramSet histograms; // 4 channels, black+RGB
                                       // % between 0 and 1
    vector<int> medianColors; // Median of histogram
    vector<int> avgColors; // Average per channel
};

#endif // VIMAGE_H
