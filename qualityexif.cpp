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
    ExifEntry* entry;
    char vals[20];

    // Aperture
    entry = exif_data_get_entry(data, EXIF_TAG_FNUMBER);
    exif_entry_get_value(entry, vals, 10);
    aperture = atof(vals+2); // get rid of "f/"

    // Exposure (shutter) time
    entry = exif_data_get_entry(data, EXIF_TAG_EXPOSURE_TIME);
    exif_entry_get_value(entry, vals, 10);
    if(vals[1] == '/')
        shutter = 1 / atof(vals+2); // get rid of "1/"
    else
        shutter = atof(vals);

    // ISO
    entry = exif_data_get_entry(data, EXIF_TAG_ISO_SPEED_RATINGS);
    exif_entry_get_value(entry, vals, 10);
    iso = atof(vals);

    // Time+date
    entry = exif_data_get_entry(data, EXIF_TAG_DATE_TIME);
    exif_entry_get_value(entry, vals, 20);
    // Get time representation as a long int, yyyymmddhhmmss
    time = 0;
    for(int i=0; i<20; ++i)
        if(isdigit(vals[i]))
            time = time*10 + (vals[i]-'0');

//    qDebug("Aperture: %f. Exposure: %f. ISO %d, time=%lld",
//           aperture, shutter, iso, time);
}
