#include <cstdlib>
#include "qualityexif.h"

QualityExif::QualityExif()
{
    dataExists = false;
    aperture = 0;
    shutter = 0;
    iso = 0;
    time = 0;
}

void QualityExif::parseContent(ExifContent* content) {
    ExifEntry* entry; const char* data;
    entry = exif_content_get_entry(content, EXIF_TAG_APERTURE_VALUE);

    // To do: This segfaults
    //data = (char*)entry->data;

    //aperture = atof(data);
    return;
}
