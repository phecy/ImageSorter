######################################################################
# Automatically generated by qmake (2.01a) Sun Feb 6 15:52:08 2011
######################################################################

TEMPLATE = app
TARGET =
DEPENDPATH += . \
              vw \
              vw/BundleAdjustment \
              vw/Camera \
              vw/Cartography \
              vw/Core \
              vw/FileIO \
              vw/HDR \
              vw/Image \
              vw/InterestPoint \
              vw/Math \
              vw/Mosaic \
              vw/Stereo \
              vw/tools \
              VisionWorkbench-2.1.0/docs/workbook \
              VisionWorkbench-2.1.0/src/test \
              vw/BundleAdjustment/tests \
              vw/Camera/tests \
              vw/Cartography/tests \
              vw/Core/tests \
              vw/FileIO/tests \
              vw/Image/tests \
              vw/InterestPoint/tests \
              vw/Math/tests \
              vw/Stereo/tests \
              VisionWorkbench-2.1.0/thirdparty/cxxtest/cxxtest \
              VisionWorkbench-2.1.0/thirdparty/cxxtest/sample \
              VisionWorkbench-2.1.0/thirdparty/gtest/src \
              VisionWorkbench-2.1.0/thirdparty/gtest/include/gtest
INCLUDEPATH += . \
               vw/Core \
               vw \
               vw/InterestPoint \
               vw/Math \
               vw/Image \
               vw/FileIO \
               vw/BundleAdjustment \
               vw/Camera \
               vw/Stereo \
               vw/Cartography \
               vw/HDR \
               vw/Mosaic

# Input
HEADERS += blurdetect.h \
           color.h \
           colorUtility.h \
           display.h \
           duplicateip.h \
           duplicaterater.h \
           duplicatesegmented.h \
           duplicatetime.h \
           exposure.h \
           findDups.h \
           grey.h \
           harmony.h \
           insertionsort.h \
           qualityexif.h \
           vimage.h \
           sharpdetect.h \
    boundingbox.h \
    boundingBoxPresets.h \
    algorithmPresets.h \
    setdisplay.h \
    duplicategaussian.h \
    duplicatehistogram.h
FORMS += display.ui \
    setdisplay.ui
SOURCES += blurdetect.cpp \
           color.cpp \
           display.cpp \
           duplicateip.cpp \
           duplicaterater.cpp \
           duplicatesegmented.cpp \
           duplicatetime.cpp \
           exposure.cpp \
           findDups.cpp \
           grey.cpp \
           harmony.cpp \
           insertionsort.cpp \
           main.cpp \
           qualityexif.cpp \
           vimage.cpp \
           sharpdetect.cpp \
    boundingbox.cpp \
    setdisplay.cpp \
    duplicategaussian.cpp \
    duplicatehistogram.cpp \
    vw/InterestPoint/InterestData.cc


LIBS +=  /usr/lib/libexif.a \
         /usr/lib/libboost*.a \
        /usr/local/lib/libvw.so \
        /usr/lib/liblapack.a \
        /usr/lib/liblapack.so
