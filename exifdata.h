#ifndef EXIFDATA_H
#define EXIFDATA_H

#include "libexif/exif-data.h"

class ExifData
{
public:
    ExifData();

    void parseData(ExifData* data);

    float getAperture() { return aperture; }
    float getShutter() { return shutter; }
    int getTime() { return time; }
    int getIso() { return iso; }

    bool isValid() { return dataExists; }

private:
    float aperture;
    float shutter;
    unsigned long long int time;
    int iso;

    bool dataExists;
};

#endif // EXIFDATA_H
