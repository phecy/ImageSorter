TARGET =

INCLUDEPATH += . \
    /var/lib

DEFINES += USE_GIST
DEFINES += STANDALONE_GIST

# Input
HEADERS += \
    similarity/content.h \
    similarity/lear_gist/gist.h \
    similarity/lear_gist/standalone_image.h \
    similarity/time.h \
    similarity/gaussian.h \
    similarity/histogram.h \
    similarity/similarity.h \
    quality/blurdetect.h \
    quality/contrast.h \
    quality/exposure.h \
    quality/grey.h \
    util/algorithmPresets.h \
    util/common.h \
    util/kurtosis.h \
    exifinfo.h \
    vimage.h \
    quality/sharpdetect.h \
    ml/getrating.h \
    ml/traindata.h \
    display/maindisplay.h \
    display/setdisplay.h \
    display/imgviewer.h \
    ml/lowlevellearner.h \
    ml/highlevellearner.h \
    ml/learnercommon.h
FORMS += \
    display/maindisplay.ui \
    display/setdisplay.ui \
    display/imgviewer.ui
SOURCES += \
    similarity/content.cpp \
    similarity/lear_gist/gist.c \
    similarity/lear_gist/standalone_image.c \
    similarity/time.cpp \
    similarity/gaussian.cpp \
    similarity/histogram.cpp \
    similarity/similarity.cpp \
    quality/blurdetect.cpp \
    quality/exposure.cpp \
    quality/contrast.cpp \
    quality/grey.cpp \
    main.cpp \
    exifinfo.cpp \
    vimage.cpp \
    quality/sharpdetect.cpp \
    ml/getrating.cpp \
    ml/traindata.cpp \
    display/maindisplay.cpp \
    display/setdisplay.cpp \
    display/imgviewer.cpp \
    ml/lowlevellearner.cpp \
    ml/highlevellearner.cpp \
    ml/learnercommon.cpp \
    util/common.cpp \
    util/kurtosis.cpp
LIBS += /usr/lib/libexif.a \
        -lfftw3f

*-g++ : QMAKE_CXXFLAGS_WARN_ON += -Wno-sign-compare \

