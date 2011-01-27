#ifndef QUALITYEXIF_H
#define QUALITYEXIF_H

#include "libexif/exif-data.h"

class QualityExif
{
public:
    QualityExif();

    void parseData(ExifData* data);

    float getAperture() { return aperture; }
    float getShutter() { return shutter; }
    int getTime() { return time; }
    int getIso() { return iso; }

    bool isValid() { return dataExists; }

private:
    float aperture;
    float shutter;
    int time;
    int iso;

    bool dataExists;
};

#endif // QUALITYEXIF_H
