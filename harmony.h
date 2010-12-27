#ifndef HARMONY_H
#define HARMONY_H

#include <QImage>
#include "color.h"


// AAAAALWAYS, I WANNA BE WITH YOU
// AND MAKE BELIEVE WITH YOU
// AND LIVE IN HARMONY, HARMONY, OH LOVE

// NOW IT IS STUCK IN YOUR HEAD TOO, MUAHAHAHAHA...



class Harmony
{
public:
    Harmony(QImage* im);
    ~Harmony();

    void firstPass();
    void secondPass();

    int Iharmony(int hue);
    int Lharmony(int hue);
    int Yharmony(int hue);
    int Xharmony(int hue);

    int Iharm[2];
    int Lharm[2];
    int Yharm[2];
    int Xharm[2];
    int iharm[2];
    int vharm[2];

    int colorChange(int hue, int shift);

    int* colorSpread(int hue, int range);// must dispose of this guy's return properly!
    

//private:
    QImage* image;
    float warmpth, chill;
    float totalColor[3];
    Color *spectrum[361]; //MUST BE FREED
    int width, height; // of the image
    int maxComp[2], maxAnalog[2], maxTri[2], maxSplit[2], maxRect[2], maxSquare[2];
    int i_vHarmony[361][2]; //i harmony is at 0, v harmony is at 1
    //int harmonies2[361][5];//I=0,L=1,T=2,Y=3,X=4

};



#endif // HARMONY_H
