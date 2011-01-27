#include <cstdlib>
#include <QDebug>
#include "qualityexif.h"

QualityExif::QualityExif()
{
    dataExists = false;
    aperture = 0;
    shutter = 0;
    iso = 0;
    time = 0;
}

void QualityExif::parseData(ExifData* data) {
    ExifEntry* entry = exif_data_get_entry(data, EXIF_TAG_FNUMBER);

    char vals[10];
    exif_entry_get_value(entry, vals, 8);

    aperture = atof(vals+2); // get rid of f/
    qDebug("Aperture: %f", aperture);
    return;
}
