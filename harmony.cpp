/*
This file is part of ImageSorter.

    ImageSorter is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ImageSorter is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ppm.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QtGui/QApplication>
#include <QtOpenGL/QGLWidget>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "harmony.h"

using namespace std;


Harmony::Harmony(QImage* im){
    image = im;

    width= image->width();
    height= image->height();

    //cout<<width<<"-"<<height<<"\n";

    warmpth=0;
    chill=0;
    totalColor[0]=0;
    totalColor[1]=0;
    totalColor[2]=0;

    for (int i=0; i<361; i++){
        Color* col= new Color(i);
        spectrum[i]=col;
        i_vHarmony[i][0]=0;
        i_vHarmony[i][1]=0;
    }

    for (int i=0; i<2; i++){
        maxComp[i]=0; //color, #of compliments found
        maxAnalog[i]=0; //color, #of occurances of analogous colors
        maxTri[i]=0; //color, #of triadic colors found
        maxSplit[i]=0;
        maxRect[i]=0;
        maxSquare[i]=0;
    }

    Iharm[0]=0;
    Lharm[0]=0;
    Yharm[0]=0;
    Xharm[0]=0;
    iharm[0]=0;
    vharm[0]=0;

    Iharm[1]=0;
    Lharm[1]=0;
    Yharm[1]=0;
    Xharm[1]=0;
    iharm[1]=0;
    vharm[1]=0;
}

Harmony::~Harmony(){
    for (int i=0; i<361; i++){
        delete spectrum[i];
    }
}

int* Harmony::colorSpread(int hue, int range){// must dispose of this guy's return properly!
    int *outArray;
    int arr[4] = {0,0,(hue-range),(hue+range)};
    outArray=arr;
    if ( ((hue+range) <=360) && ((hue-range) >=0) ) return outArray;

    if((hue+range) >=360) {arr[1]=(hue+range)-360; arr[3]=360;}

    if((hue-range) <=0){arr[2]=(hue-range)+360; arr[3]=360; arr[1]=hue;}
    return outArray;
}

void Harmony::firstPass(){
    //tmp debugging stuff

    float tmpTC[3]={0,0,0};
    float tmpW=0;
    float tmpC=0;

    QColor color;
    for (int i=0; i<width; i++) { //Goes throught the pixels to count all the values
        for (int j=0; j<height/1; j++) {
            color = image->pixel(i,j);
            if(color.hue()<0) continue;
            spectrum[color.hue()]->seen();
            tmpTC[0]+=(color.hue());
            tmpTC[1]+=(color.saturation());
            tmpTC[2]+=(color.value());

                //(hue<=300)&&(hue>120) returns true for cold colors

            int hue=color.hue();
            if (!((hue<=300)&&(hue>120))) tmpW=tmpW+1;
            if ((hue<=300)&&(hue>120)) tmpC=tmpC+1;
        }
        if(tmpTC[0]!=0)totalColor[0]=totalColor[0]+(tmpTC[0]/height);
        if(tmpTC[1]!=0)totalColor[1]=totalColor[1]+(tmpTC[1]/height);
        if(tmpTC[2]!=0)totalColor[2]=totalColor[2]+(tmpTC[2]/height);
        if(tmpW!=0)warmpth = warmpth+(tmpW/height);
        if(tmpC!=0)chill = chill+(tmpC/height);

        tmpW=0;tmpC=0;tmpTC[0]=0;tmpTC[1]=0;tmpTC[2]=0 ;//Clear tmp variables!!!
    }

    totalColor[0]=(totalColor[0]/width);
    totalColor[1]=(totalColor[1]/width);
    totalColor[2]=(totalColor[2]/width);
    warmpth = (warmpth/width);
    chill= (chill/width);

    //calculating v and i
    for (int i=0; i<361; i++){
        int* params=Harmony::colorSpread(i, 5);
        //cout << params[0] <<" "<<params[1]<<" "<<params[2]<<" "<<params[3]<<"\n";
        for (int j=params[0]; j<params[1]; j++){
            i_vHarmony[i][0]= i_vHarmony[i][0]+(spectrum[j]->getSeen());
        }
        for (int j=params[2]; j<params[3]; j++){
            i_vHarmony[i][0]=i_vHarmony[i][0]+(spectrum[j]->getSeen());
        }

        params=Harmony::colorSpread(i, 45);
        for (int j=params[0]; j<params[1]; j++){
            i_vHarmony[i][1]=i_vHarmony[i][1]+(spectrum[j]->getSeen());
        }
        for (int j=params[2]; j<params[3]; j++){
            i_vHarmony[i][1]=i_vHarmony[i][1]+(spectrum[j]->getSeen());
        }

        //cout << i<<" "<<i_vHarmony[i][0]<<" "<<i_vHarmony[i][1]<<"\n";
    }
}

int Harmony::colorChange(int hue, int shift){
    int out = hue+shift;
    if (out >360) out=out-360;
    if (out<0) out=out+360;
    return out;
}

int Harmony::Iharmony(int hue) {
    int newHue=Harmony::colorChange(hue, 180);
    return i_vHarmony[hue][0]+ i_vHarmony[newHue][0];
}

int Harmony::Lharmony(int hue){
    int newHue=Harmony::colorChange(hue, 90);
    return i_vHarmony[hue][0]+ i_vHarmony[newHue][1];
}


int Harmony::Yharmony(int hue){
    int newHue=Harmony::colorChange(hue, 180);
    return i_vHarmony[hue][1]+ i_vHarmony[newHue][0];
}

int Harmony::Xharmony(int hue){
    int newHue=Harmony::colorChange(hue, 180);
    return i_vHarmony[hue][1]+ i_vHarmony[newHue][1];
}

void Harmony::secondPass(){

    for (int i=0; i<361; i++){
        // calculating the other types of harmonies: do it here
        int harm;
        harm=Iharmony(i);
        if (harm > Iharm[1]) {Iharm[0]=i; Iharm[1]=harm;}
        harm=Lharmony(i);
        if (harm > Lharm[1]) {Lharm[0]=i; Lharm[1]=harm;}
        harm=Yharmony(i);
        if (harm > Yharm[1]) {Yharm[0]=i; Yharm[1]=harm;}
        harm=Xharmony(i);
        if (harm > Xharm[1]) {Xharm[0]=i; Xharm[1]=harm;}

        harm=i_vHarmony[i][0];
        if (harm > iharm[1]) {iharm[0]=i; iharm[1]=harm;}
        harm=i_vHarmony[i][1];
        if (harm > vharm[1]) {vharm[0]=i; vharm[1]=harm;}

    }
    //cout<<width*height<<",";
    //cout<<"Hue,"<<totalColor[0]<<",Sat,"<<totalColor[1]<<",Val,"<<totalColor[2]<<",";
    //if (warmpth> chill) cout<<"warm,";
    //if (warmpth< chill) cout<<"cold,";
    //if (warmpth== chill) cout<<"neutral,";
    //cout<<"i,"<<iharm[0]<<","<<iharm[1]<<",";
    //cout<<"v,"<<vharm[0]<<","<<vharm[1]<<",";
    //cout<<"I,"<<Iharm[0]<<","<<Iharm[1]<<",";
    //cout<<"L,"<<Lharm[0]<<","<<Lharm[1]<<",";
    //cout<<"Y,"<<Yharm[0]<<","<<Yharm[1]<<",";
    //cout<<"X,"<<Xharm[0]<<","<<Xharm[1]<<"\n";
}



