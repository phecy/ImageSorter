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

#ifndef COLOR_H
#define COLOR_H


class Color {

public:
    Color(int hue);
    ~Color();
    int newColor (int color, int change);

    int getComp(){return compliment;};
    int* getTriad(){return triadic;};
    int* getAnalog(){return analogies;};
    int* getSplit(){return splitComp;};
    int* getRect(){return rectangle;};
    int* getSq(){return square;};

    void seen(){occurances= occurances+1;};
    int getSeen(){return occurances;};

private:
    void calculateFormula (int color);//NOTE: you have to run this, then use the output c++ code
    //to manually update the files here if you want to mess with the formulas.
    void setCompliment(int comp){compliment = comp;};
    void setAnalogous(int i, int value){analogies[i]=value;};
    void setTriadic(int first, int second){triadic[0]=first; triadic[1]=second;};
    void setSplitComp(int first, int second){splitComp[0]=first; splitComp[1]=second;};
    void setRectangle(int first, int second, int third){rectangle[0]=first; rectangle[1]=second; rectangle[2]=third;};
    void setSquare(int first, int second, int third){square[0]=first; square[1]=second; square[2]=third;};
    void setHue(int h){hue=h;};

    int compliment;
    int analogies[60];
    int triadic[2];
    int splitComp[2];
    int rectangle[3];
    int square[3];
    int hue;
    int occurances;


 };

#endif // COLOR_H
