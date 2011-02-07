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

using namespace vw;
using namespace vw::ip;

typedef ImageView<PixelRGB<uint8> > VImage_t;

/*DEBUG class QMainWindow;*/
class VImage/*DEBUG : public QMainWindow*/
{
public:
    VImage(char* filename);
    VImage(const VImage&);

    QImage* getQImage() { return qimage; }
    VImage_t* getVImage() {return vimage; }
    uchar* getUchar() {return qimage->bits(); }
    char* getFilename() { return filename; }
    InterestPointList getIp() { return ipList; }
    void setIp(InterestPointList ip) { ipList = ip; }

private:
    void setData(uchar* data);
    void makeQImage();

    VImage_t* vimage;
    QImage* qimage;
    InterestPointList ipList;
    char* filename;
    int width;
    int height;
};

#endif // VIMAGE_H
