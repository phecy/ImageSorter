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

using namespace std;
using namespace vw;
using namespace vw::ip;

typedef ImageView<PixelRGB<uint8> > VImage_t;
typedef pair<int,int> point;
typedef pair<point,point> boundingBox;

/*DEBUG class QMainWindow;*/
class VImage/*DEBUG : public QMainWindow*/
{
public:
    VImage(char* filename);
    VImage(const VImage&);
    ~VImage();

    // Data
    QImage* getQImage() { return qimage; }
    VImage_t* getVImage() {return vimage; }
    uchar* getUchar() {return qimage->bits(); }

    // Information
    string getFilename() { return filename; }

    // Foreground stuff
    InterestPointList getIps() { return ipList; }
    void setIp(InterestPointList ip) { ipList = ip; }

    boundingBox getForegroundCoords() { return foregroundCoords; }
    QImage* getForeground() { return foreground; }
    void setForeground(boundingBox coords);

private:
    void setData(uchar* data);
    void makeQImage();

    // Data
    VImage_t* vimage;
    QImage* qimage;

    // Information
    string filename;
    int width;
    int height;

    // Foreground stuff
    InterestPointList ipList;
    boundingBox foregroundCoords;
    QImage* foreground;
};

#endif // VIMAGE_H
