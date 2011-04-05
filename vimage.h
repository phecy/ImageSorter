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

#include "vw/Core.h"
#include "vw/InterestPoint.h"
#include "vw/Image.h"

#define HNUMCOLORS 4
#define HBLACK 0
#define HRED 1
#define HGREEN 2
#define HBLUE 3

using namespace std;
using namespace vw;
using namespace vw::ip;

typedef ImageView<PixelRGB<uint8> > VImage_t;
typedef pair<int,int> point;
typedef pair<point,point> boundingBox;
typedef vector<float> histogramChannel;
typedef vector<histogramChannel> histogramSet;

/*DEBUG class QMainWindow;*/
class VImage/*DEBUG : public QMainWindow*/
{
public:
    VImage(char* filename);
    ~VImage();

    // Data
    QImage* getQImage() { return qimage; }
    VImage_t* getVImage() {return vimage; }
    uchar* getUchar() {return qimage->bits(); }

    // Information
    char* getFilename() { return filename; }
    char* getFullpath() { return fullpath; }
    int getIndex() { return index; }
    void setIndex(int i) { index=i; }
    int getWidth() { return width; }
    int getHeight() { return height; }
    int getOrigWidth() { return origwidth; }
    int getOrigHeight() { return origheight; }

    // Ranks
    // Rank = 0-10 rating.
    // Adjusted rank = rank adjusted for set
    void setRank(float r) { rankTotal=r; adjustedRank=r; }
    float getRank() { return rankTotal; }
    void setSetNum(float s) { setNum = s; }
    int getSetNum() { return setNum; }
    void multiplyAdjustedRank(float k) { adjustedRank *= k; }
    void subAdjustedRank(float k) { adjustedRank -= k; }
    float getAdjustedRank() { return adjustedRank; }
    void setRanks(vector<int> r) { ranks = r; }
    vector<int> getRanks() { return ranks; }

    // Foreground stuff
    InterestPointList getIps() { return ipList; }
    void setIp(InterestPointList ip) { ipList = ip; }

    boundingBox getForegroundCoords() { return foregroundCoords; }
    QImage* getForeground() { return foreground; }
    void setForeground(boundingBox coords);

    // For sharpdetect and duplicategaussian
    // Returns avg pixel difference
    static int avgPixelDiff(VImage_t one, VImage_t two);

    // Returns the area of the given box in the fg
    int amountInForeground(boundingBox);

    // Colors
        // Make histogram starting at QImage's (x,y)
    static histogramSet makeHistograms
                    (VImage* vim, int x, int y, int width, int height);
    const histogramSet& getHistogram() { return histograms; }
    histogramChannel getHistogramK() { return histograms[HBLACK]; }
    histogramChannel getHistogramR() { return histograms[HRED]; }
    histogramChannel getHistogramG() { return histograms[HGREEN]; }
    histogramChannel getHistogramB() { return histograms[HBLUE]; }
    const vector<int>& getMedians() { return medianColors; }
    int getMedGray() { return medianColors[HBLACK]; }
    int getMedRed() { return medianColors[HRED]; }
    int getMedGreen() { return medianColors[HGREEN]; }
    int getMedBlue() { return medianColors[HBLUE]; }

private:
    void setData(uchar* data);
    void makeQImage();
    void makeMedianColors();

    // Data
    VImage_t* vimage;
    QImage* qimage; // Scaled to 800px wide

    // Information
    char* filename;
    char* fullpath;
    int index;
    int width, height; // Width scaled to 800px
    int origwidth, origheight; // VImage_t width+height

    // Ranks
    float rankTotal;
    int setNum;
    float adjustedRank; // Rank adjusted for sets
    vector<int> ranks; // Vals for each rank

    // Foreground stuff
    InterestPointList ipList;
    boundingBox foregroundCoords;
    QImage* foreground;

    // Colors
    histogramSet histograms; // 4 channels, black+RGB
                                       // % between 0 and 1
    vector<int> medianColors; // Median of histogram
};

#endif // VIMAGE_H
