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
#include <QColor>
#include "grey.h"


grey::grey()
{
}
int grey::calcGrey(QImage* im)
{
    int middle_gray = 85;
    float average = 0.0;

    QImage image = *im;

    //if (image.load(q_image_name)) qDebug("Image loaded successfully");
    //qDebug("%d %d", image.width(), image.height());
    //qDebug("setting variables");
    //qDebug("int variables set");
    //qDebug("array created");
    for (int argi = 0; argi < image.width(); ++argi)
    {
      for (int argt = 0; argt < image.height(); ++argt)
      {
        QColor color = QColor(image.pixel(argi, argt));
        average += (float)color.lightness();
      }
    }

    average /= (image.width() * image.height());

    //qDebug("Average = %f", average);

    int rank = 9;
    float difference = 0;
    int upper_div = (255 - middle_gray) / 10;
    int lower_div = middle_gray / 10;
    //qDebug("%d", upper_div);
    //qDebug("%d", lower_div);
    if (average >= middle_gray)
    {
      difference = average - middle_gray;
      if ((int)difference % upper_div > (float)(upper_div / 2)) rank -= 1;
      rank -= (int)(difference / upper_div);
      //qDebug ("higher than 84");
    }
    else
    {
      difference = (middle_gray - 1) - average;
      if ((int)difference % lower_div > (float)(lower_div / 2)) rank -= 1;
      rank -= (int)(difference / lower_div);
      //qDebug("lower than 85");
    }
    if (rank < 0) rank = 0;
    //qDebug("%d", rank);
    return rank;
}
