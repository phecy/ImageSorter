/*
This file is part of ppm.

    ppm is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ppm is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ppm.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef COLORUTILITY_H
#define COLORUTILITY_H
#include "harmony.h"
#include <cstdlib>
#include <QImage>

using namespace std;

int isWarm (int H) {
    if ((H<=300)&&(H>120)) return false;
    else return true;
} //returns 1 if warm, 2 if cool, and 0 if neutral

float harmonyEvaluation(float I, float L, float X, float Y, float vcount, float icount ,  int saturation, int temperatureAgreement){
    if (saturation>=135){
        if (I>=0.4){
            float factor=Y-I;
            if(factor<0.2) return 8;
            if(factor<0.26)return 7;
            if(factor<0.35)return 6;
            if(factor<0.5)return 4;
        }
        if (X>=0.75){
            float factor=X-Y;
            if(factor<0.007) return 4;
            if(factor<0.016)return 5;
            if(factor<0.02)return 6;
            if(factor<0.05)return 8;
        }
        if ((L>=0.6)&&(L<=0.7)) return 7;
        else return 4+temperatureAgreement; //it's slipping throught the cracks...I'm just taking a guess.
    }
    if (saturation>=80){
        if (I>=0.4){
            return 4;
        }
        if (L>=0.55){
            float factor=(L-icount)/L;
            if(factor<0.31) return 5;
            if(factor<0.37)return 6;
        }
        if (X>=0.75){
            float factor=X-Y;
            if(factor<0.003) return 4;
            if(factor<0.004)return 6;
        }
        if (vcount<=0.45) return 7;
        if (icount>0.19) return 6;
        if (icount<=0.19) return 3.5;
        else return 2+temperatureAgreement; //it's slipping throught the cracks...I'm just taking a guess.
    }
    else {
        if (X>=0.75){
            float factor=X-Y;
            if(factor<0.03) return 3.5;
            if(factor<0.15)return 3;
            else return 5;
        }
        if ((icount>=0.16)&&(icount<=0.36)) return 5;
        if ((X>=0.5)&&(X<=0.75)) return 4;
        else return 1+temperatureAgreement; //it's slipping throught the cracks...I'm just taking a guess.
    }
}

float colorAnalysis(QImage* im){
    Harmony *TBP= new Harmony(im);
    TBP->firstPass();
    TBP->secondPass();

    float outFloat=0;
    float warmpth = TBP->warmpth;
    float chill = TBP->chill;

    int pixels = (TBP->width)*(TBP->height);
    float Iscaled = TBP->Iharm[1]/pixels;
    float Lscaled = TBP->Lharm[1]/pixels;
    float Xscaled = TBP->Xharm[1]/pixels;
    float Yscaled = TBP->Yharm[1]/pixels;
    float vscaled = TBP->vharm[1]/pixels;
    float iscaled = TBP->iharm[1]/pixels;
    int saturation = TBP->totalColor[2];

    int temperatureAgreement=0; //Higher is good, note that symmetric harmonies don't work for this
    bool overallWarm=false;
    if (warmpth > chill) overallWarm = true;
    if (!(warmpth == chill)) { // if warmth and chill are not equal, then temperature agreement is valid
        if (isWarm(TBP->Lharm[0])&&overallWarm) temperatureAgreement= temperatureAgreement+Lscaled;
        else temperatureAgreement= temperatureAgreement-Lscaled;
        if (isWarm(TBP->Iharm[0])&&overallWarm) temperatureAgreement= temperatureAgreement+Iscaled;
        else temperatureAgreement= temperatureAgreement-Iscaled;
        if (isWarm(TBP->Yharm[0])&&overallWarm) temperatureAgreement= temperatureAgreement+Yscaled;
        else temperatureAgreement= temperatureAgreement-Yscaled;
        if (isWarm(TBP->Xharm[0])&&overallWarm) temperatureAgreement= temperatureAgreement+Xscaled;
        else temperatureAgreement= temperatureAgreement-Xscaled;
        if (isWarm(TBP->iharm[0])&&overallWarm) temperatureAgreement= temperatureAgreement+iscaled;
        else temperatureAgreement= temperatureAgreement-iscaled;
        if (isWarm(TBP->vharm[0])&&overallWarm) temperatureAgreement= temperatureAgreement+vscaled;
        else temperatureAgreement= temperatureAgreement-vscaled;
    }

    float harmonyEval= harmonyEvaluation( Iscaled,  Lscaled,  Xscaled,  Yscaled,  vscaled,  iscaled ,  saturation, temperatureAgreement);

    outFloat =(harmonyEval);

    if(outFloat<0) outFloat=0;
    if(outFloat>10)outFloat=10;

    delete(TBP);
    TBP=NULL;
    if (outFloat <1) outFloat=1;
    return outFloat;
}



#endif // COLORUTILITY_H
