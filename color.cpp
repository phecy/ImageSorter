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

#include "color.h"

Color::Color(int hue)
{
    setHue(hue);
    calculateFormula(hue);
    occurances =0;

}


Color::~Color(){
}

int Color::newColor (int color, int change) {
    int outColor = color + change;
    if (outColor >360) outColor = outColor-360;
    else if (outColor <0) outColor = outColor+360;
    return outColor;
}

void Color::calculateFormula (int color){
    int analogSpread=60;

    compliment= newColor(color, 180);

    int span=analogSpread/2;
    for (int i=0; i<analogSpread; i++){
        analogies[i]= newColor(color, span);
        i++;
        analogies[i]= newColor(color, span*(-1));
        span= span-1;

    }

    triadic[0]=newColor(color, 120);
    triadic[1]=newColor(color, -120);

    splitComp[0]=newColor(color, 150);
    splitComp[1]=newColor(color, -150);

    rectangle[0]=newColor(color, 60);
    rectangle[1]=newColor(color, 180);
    rectangle[2]=newColor(color, -60);

    square[0]=newColor(color, 90);
    square[1]=newColor(color, 180);
    square[2]=newColor(color, -90);

}
