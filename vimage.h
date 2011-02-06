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

#include "VisionWorkbench-2.1.0/src/vw/Core.h"
#include <vw/Image/PixelTypeInfo.h>
#include "VisionWorkbench-2.1.0/src/vw/InterestPoint.h"
#include "VisionWorkbench-2.1.0/src/vw/Image.h"
#include "VisionWorkbench-2.1.0/src/vw/FileIO.h"

using namespace vw;

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

private:
    void setData(uchar* data);
    void makeQImage();

    VImage_t* vimage;
    QImage* qimage;
    char* filename;
    int width;
    int height;
};

#endif // VIMAGE_H
