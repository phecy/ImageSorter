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

#include <QImage>
#include <QDebug>
#include "exposure.h"

#include <iostream>

using namespace std;

exposure::exposure(){
}

int exposure::expose(QImage* im){
    int width = im->width();
    int height = im->height();
    int *histogram = new int[256]();
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            int gray = qGray (im->pixel (x, y));
            histogram[gray]++;
        }
    }

    int rank = 0;
    float Total_sum = 0.00;
    float S1 = 0.00;
    float S2 = 0.00;
    float S3 = 0.00;
    float S4 = 0.00;
    float S5 = 0.00;
    float S6 = 0.00;
    float S7 = 0.00;
    float S8 = 0.00;
    float S9 = 0.00;
    float S10 = 0.0;
    float S11 = 0.00;

    for(int i = 0; i < 256; i++){
        Total_sum += histogram[i];
    }


    for(int i = 0; i < 24; i++){
        S1 += histogram[i];
    }
    for(int i = 24; i < 47; i++){
        S2 += histogram[i];
    }
    for(int i = 47; i < 70; i++){
        S3 += histogram[i];
    }
    for(int i = 70; i < 93; i++){
        S4 += histogram[i];
    }
    for(int i = 93; i < 116; i++){
        S5 += histogram[i];
    }
    for(int i = 116; i < 139; i++){
        S6 += histogram[i];
    }
    for(int i = 139; i < 162; i++){
        S7 += histogram[i];
    }
    for(int i = 162; i < 185; i++){
        S8 += histogram[i];
    }
    for(int i = 185; i < 208; i++){
        S9 += histogram[i];
    }
    for(int i = 208; i < 231; i++){
        S10 += histogram[i];
    }
    for(int i = 231; i < 256; i++){
        S11 += histogram[i];
    }


    bool under_over = false;

    if((S1) >= (0.30*Total_sum) && (S11) >= (0.30*Total_sum)){
        rank = 0;
        under_over = true;
    }
    else if((S1+S2) >= (0.30*Total_sum) && (S10+S11) >= (0.30*Total_sum)){
        rank = 2;
        under_over = true;
    }
    else if((S1+S2+S3) >= (0.30*Total_sum) && (S9+S10+S11) >= (0.30*Total_sum)){
        rank = 4;
        under_over = true;
    }
    else if((S1+S2+S3+S4) >= (0.30*Total_sum) && (S8+S9+S10+S11) >= (0.30*Total_sum)) {
        rank = 6;
        under_over = true;
    }
    else if((S1+S2+S3+S4+S5) >= (0.36*Total_sum) && (S7+S8+S9+S10+S11) >= (0.36*Total_sum)) {
        rank = 8;
        under_over = true;
    }


    /*for(int i = 0; i < 256; i++) {
           qDebug() << i << ":" << histogram[i];
    }
    qDebug() <<rank;*/

    if(under_over) /*return a.exec();*/ return rank;


    if((S1) >= (0.85*Total_sum) || (S11) >= (0.85*Total_sum)) rank = 0;
    else if((S1+S2) >= (0.85*Total_sum) || (S10+S11) >= (0.85*Total_sum)) rank = 1;
    else if((S1+S2+S3) >= (0.85*Total_sum) || (S9+S10+S11) >= (0.85*Total_sum)) rank = 2;
    else if((S1+S2+S3+S4) >= (0.85*Total_sum) || (S8+S9+S10+S11) >= (0.85*Total_sum)) rank = 3;
    else if((S1+S2+S3+S4+S5) >= (0.85*Total_sum) || (S7+S8+S9+S10+S11) >= (0.85*Total_sum)) rank = 4;
    else if((S1+S2+S3+S4+S5+S6) >= (0.85*Total_sum) || (S6+S7+S8+S9+S10+S11) >= (0.85*Total_sum)) rank = 5;
    else if((S1+S2+S3+S4+S5+S6+S7) >= (0.85*Total_sum) || (S5+S6+S7+S8+S9+S10+S11) >= (0.85*Total_sum)) rank = 6;
    else if((S1+S2+S3+S4+S5+S6+S7+S8) >= (0.85*Total_sum) || (S4+S5+S6+S7+S8+S9+S10+S11) >= (0.85*Total_sum)) rank = 7;
    else if((S1+S2+S3+S4+S5+S6+S7+S8+S9) >= (0.85*Total_sum) || (S3+S4+S5+S6+S7+S8+S9+S10+S11) >= (0.85*Total_sum)) rank = 8;
    else if((S1+S2+S3+S4+S5+S6+S7+S8+S9+S10) >= (0.90*Total_sum) || (S2+S3+S4+S5+S6+S7+S8+S9+S10+S11) >= (0.90*Total_sum)) rank = 9;
    else rank = 10;


    delete[] histogram;
    // im->~QImage();

   /* for(int i = 0; i < 256; i++) {
           qDebug() << i << ":" << histogram[i];
    }*/
    //qDebug() <<Total_sum;
    //qDebug() <<rank;
    //return a.exec();
    if(rank > 9)
        rank = 9;
    return rank;


}
