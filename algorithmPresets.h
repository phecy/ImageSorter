#ifndef ALGORITHMPRESETS_H
#define ALGORITHMPRESETS_H

#include "vimage.h"

bool loadPreset(VImage* vim, int i,
                int* exposeVals, int* palletVals, int* greyVals,
                int* blurVals, int* sharpVals) {

    if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0031.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 6;
    //          picValue[i] = 6.76201;
    //   Blur: 6
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0034.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 2;
    //          picValue[i] = 4.51198;
    //   Blur: 2
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0035.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 0;
              sharpVals[i] = 2;
    //          picValue[i] = 3.14905;
    //   Blur: 2
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0037.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 7;
    //          picValue[i] = 9;
    //   Blur: 7
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0039.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 7;
    //          picValue[i] = 9;
    //   Blur: 7
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0046.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 3;
              sharpVals[i] = 7;
    //          picValue[i] = 9;
    //   Blur: 7
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0048.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0049.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0055.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0056.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0059.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0060.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0062.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0064.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 2;
              sharpVals[i] = 8;
    //          picValue[i] = 9;
    //   Blur: 8
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0067.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0069.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 7;
    //          picValue[i] = 7.80267;
    //   Blur: 7
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0072.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0073.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0074.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0075.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0076.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0077.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0078.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0079.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 1;
               greyVals[i] = 3;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0080.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0082.JPG") == 0) {
             exposeVals[i] = 1;
             palletVals[i] = 1;
               greyVals[i] = 1;
               blurVals[i] = 9;
              sharpVals[i] = 4;
    //          picValue[i] = 3.54843;
    //   Blur: 4
    //   Exposure: 1
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0083.JPG") == 0) {
             exposeVals[i] = 1;
             palletVals[i] = 1;
               greyVals[i] = 1;
               blurVals[i] = 2;
              sharpVals[i] = 4;
    //          picValue[i] = 3.54843;
    //   Blur: 4
    //   Exposure: 1
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0084.JPG") == 0) {
             exposeVals[i] = 1;
             palletVals[i] = 1;
               greyVals[i] = 1;
               blurVals[i] = 9;
              sharpVals[i] = 4;
    //          picValue[i] = 3.54843;
    //   Blur: 4
    //   Exposure: 1
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0085.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 1;
               blurVals[i] = 3;
              sharpVals[i] = 4;
    //          picValue[i] = 4.07301;
    //   Blur: 4
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0086.JPG") == 0) {
             exposeVals[i] = 1;
             palletVals[i] = 1;
               greyVals[i] = 1;
               blurVals[i] = 1;
              sharpVals[i] = 4;
    //          picValue[i] = 3.54843;
    //   Blur: 4
    //   Exposure: 1
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0087.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0090.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0091.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0093.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0094.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0096.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0097.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0098.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 5;
              sharpVals[i] = 6;
    //          picValue[i] = 6.34512;
    //   Blur: 6
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0099.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 1;
              sharpVals[i] = 4;
    //          picValue[i] = 4.50012;
    //   Blur: 4
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0100.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 5;
              sharpVals[i] = 5;
    //          picValue[i] = 5.39534;
    //   Blur: 5
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0101.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 9;
              sharpVals[i] = 6;
    //          picValue[i] = 6.34512;
    //   Blur: 6
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0102.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 6;
              sharpVals[i] = 7;
    //          picValue[i] = 7.34896;
    //   Blur: 7
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0103.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 4;
              sharpVals[i] = 8;
    //          picValue[i] = 8.89731;
    //   Blur: 8
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0104.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 1;
              sharpVals[i] = 7;
    //          picValue[i] = 7.34896;
    //   Blur: 7
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0105.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 3;
              sharpVals[i] = 6;
    //          picValue[i] = 6.34512;
    //   Blur: 6
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0106.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 1;
              sharpVals[i] = 6;
    //          picValue[i] = 6.34512;
    //   Blur: 6
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0107.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 7;
              sharpVals[i] = 7;
    //          picValue[i] = 7.34896;
    //   Blur: 7
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0109.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 7;
    //          picValue[i] = 7.34896;
    //   Blur: 7
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0110.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0111.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0114.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0115.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0116.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0117.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0119.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0120.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0121.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0122.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 7;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0126.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0127.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0128.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0130.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0131.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0137.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0139.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0140.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0142.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0143.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0146.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0147.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0148.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0150.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0151.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0152.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0153.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0155.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0156.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0157.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0158.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0159.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0160.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0162.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0163.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0166.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0167.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0173.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0174.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0175.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0176.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0177.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0178.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0179.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0180.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0181.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0182.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0183.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0184.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0185.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0186.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0187.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0188.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0189.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0190.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0191.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0192.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0193.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0196.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0197.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0198.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0199.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0200.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0201.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0202.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0205.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0209.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0214.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0216.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0218.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0219.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0220.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 7;
    //          picValue[i] = 7.80267;
    //   Blur: 7
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0221.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 9;
              sharpVals[i] = 6;
    //          picValue[i] = 6.76201;
    //   Blur: 6
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0223.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 5;
              sharpVals[i] = 7;
    //          picValue[i] = 9;
    //   Blur: 7
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0224.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 8;
              sharpVals[i] = 8;
    //          picValue[i] = 9;
    //   Blur: 8
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0225.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0226.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 1;
              sharpVals[i] = 8;
    //          picValue[i] = 9;
    //   Blur: 8
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0227.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0228.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 8;
              sharpVals[i] = 8;
    //          picValue[i] = 9;
    //   Blur: 8
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0229.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 7;
    //          picValue[i] = 9;
    //   Blur: 7
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0231.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0232.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0233.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0234.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0235.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0236.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0237.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 7;
    //          picValue[i] = 9;
    //   Blur: 7
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0238.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 2;
              sharpVals[i] = 8;
    //          picValue[i] = 9;
    //   Blur: 8
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0239.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 7;
              sharpVals[i] = 7;
    //          picValue[i] = 8.82886;
    //   Blur: 7
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0240.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 4;
              sharpVals[i] = 6;
    //          picValue[i] = 8.39866;
    //   Blur: 6
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0241.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0243.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0251.JPG") == 0) {
             exposeVals[i] = 0;
             palletVals[i] = 1;
               greyVals[i] = 0;
               blurVals[i] = 2;
              sharpVals[i] = 5;
    //          picValue[i] = 3.7603;
    //   Blur: 5
    //   Exposure: 0
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0252.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 1;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 8.85561;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0253.JPG") == 0) {
             exposeVals[i] = 8;
             palletVals[i] = 7;
               greyVals[i] = 2;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 8
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0254.JPG") == 0) {
             exposeVals[i] = 9;
             palletVals[i] = 7;
               greyVals[i] = 2;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 9
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0255.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0259.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0261.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0262.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0263.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0264.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0265.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0267.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0268.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0269.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0270.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0277.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0278.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0279.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0280.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0281.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0283.JPG") == 0) {
             exposeVals[i] = 0;
             palletVals[i] = 1;
               greyVals[i] = 0;
               blurVals[i] = 6;
              sharpVals[i] = 8;
    //          picValue[i] = 6.26702;
    //   Blur: 8
    //   Exposure: 0
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0285.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 6;
    //          picValue[i] = 6.09902;
    //   Blur: 6
    //   Exposure: 2
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0002.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0004.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0005.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0009.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0010.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0012.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0015.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0017.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0029.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0031.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0033.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0034.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0035.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 4;
              sharpVals[i] = 5;
    //          picValue[i] = 7.32706;
    //   Blur: 5
    //   Exposure: 6
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0036.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 7;
              sharpVals[i] = 7;
    //          picValue[i] = 9;
    //   Blur: 7
    //   Exposure: 7
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0037.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 9;
              sharpVals[i] = 5;
    //          picValue[i] = 7.91894;
    //   Blur: 5
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0039.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0041.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0042.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0043.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0046.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0047.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0050.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0051.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0053.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0055.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0057.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0058.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0061.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 4;
               blurVals[i] = 9;
              sharpVals[i] = 3;
    //          picValue[i] = 3.27817;
    //   Blur: 3
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0066.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0070.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0074.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0075.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0076.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0078.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0080.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 1;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 5;
    //          picValue[i] = 6.10737;
    //   Blur: 5
    //   Exposure: 4
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0081.JPG") == 0) {
             exposeVals[i] = 18;
             palletVals[i] = 1;
               greyVals[i] = 8;
               blurVals[i] = 0;
              sharpVals[i] = 5;
    //          picValue[i] = 9;
    //   Blur: 5
    //   Exposure: 18
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0082.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 5;
    //          picValue[i] = 6.6406;
    //   Blur: 5
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0084.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0089.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0092.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0093.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 4;
    //          picValue[i] = 6.79563;
    //   Blur: 4
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0094.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 4;
    //          picValue[i] = 6.79563;
    //   Blur: 4
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0095.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 3;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 8.85561;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0099.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0100.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0101.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0103.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0106.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0111.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 5;
              sharpVals[i] = 7;
    //          picValue[i] = 6.78287;
    //   Blur: 7
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0112.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0113.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0115.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0126.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 5;
    //          picValue[i] = 5.7758;
    //   Blur: 5
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0129.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0137.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0138.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0141.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0142.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0145.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0147.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0148.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0152.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0153.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0156.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0001.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0002.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0003.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0004.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0005.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0006.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0007.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0008.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0009.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0010.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0011.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0012.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0013.JPG") == 0) {
             exposeVals[i] = 8;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 8
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0014.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0015.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0016.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0017.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0018.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0019.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0020.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0021.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0022.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0023.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0024.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0025.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0026.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0027.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0028.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0029.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0030.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0031.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0032.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0033.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0034.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0035.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0036.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0037.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0038.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0039.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0040.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0041.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0042.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0043.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0044.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0045.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0046.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0047.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0048.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0049.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0050.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0051.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0052.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0053.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0054.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0055.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0056.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0057.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0058.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0059.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0060.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0061.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0062.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0063.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0064.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0065.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0066.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0067.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0068.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0069.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0070.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0071.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0072.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0073.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0074.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0075.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0076.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0077.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0078.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0079.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0080.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0081.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0082.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0083.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0084.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0085.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0086.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0087.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0088.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0089.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0090.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0091.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0092.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0093.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0094.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0095.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0096.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0097.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0098.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0099.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0100.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0101.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0102.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0103.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0104.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0105.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0106.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0107.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0108.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0109.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0110.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0111.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0112.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0113.JPG") == 0) {
             exposeVals[i] = 8;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 8
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0114.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0115.JPG") == 0) {
             exposeVals[i] = 8;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 8
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0116.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0117.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0118.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0119.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0120.JPG") == 0) {
             exposeVals[i] = 8;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 8
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0121.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0122.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0123.JPG") == 0) {
             exposeVals[i] = 8;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 8
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0124.JPG") == 0) {
             exposeVals[i] = 8;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 8
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0125.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0126.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0127.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0128.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0129.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 9;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0130.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0131.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 6;
    //          picValue[i] = 6.34512;
    //   Blur: 6
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0132.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 9;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0133.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 8;
    //          picValue[i] = 9;
    //   Blur: 8
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0134.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 9;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0135.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0136.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0137.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 3;
              sharpVals[i] = 7;
    //          picValue[i] = 8.82886;
    //   Blur: 7
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0138.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0139.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0140.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0141.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0142.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0143.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0144.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0145.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0146.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0147.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0148.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0149.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0150.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0151.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0152.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0153.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0154.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0155.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0156.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0157.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0158.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0159.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0160.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0161.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0162.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0163.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0164.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0165.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0166.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0167.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0168.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0169.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0170.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0171.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0172.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0173.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0174.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0175.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0176.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0177.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0178.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0179.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0180.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0181.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0183.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0184.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0185.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0186.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0187.JPG") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0188.JPG") == 0) {
             exposeVals[i] = 1;
             palletVals[i] = 1;
               greyVals[i] = 1;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 8.03298;
    //   Blur: 9
    //   Exposure: 1
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0189.JPG") == 0) {
             exposeVals[i] = 1;
             palletVals[i] = 1;
               greyVals[i] = 1;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 8.03298;
    //   Blur: 9
    //   Exposure: 1
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0190.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0191.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0192.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0193.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0194.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0195.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0196.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 1;
               greyVals[i] = 3;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0197.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0198.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0199.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0200.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0201.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0202.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0203.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0204.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0205.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0206.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0207.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0208.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0209.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0210.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0211.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0212.JPG") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 8.85561;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0213.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0214.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0215.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0216.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0217.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0218.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0219.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0220.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0221.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0222.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0223.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0224.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0225.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0226.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0227.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0228.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0229.JPG") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0230.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0231.JPG") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0232.JPG") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0233.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0234.JPG") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/1843.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 4;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/4992.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 8.85561;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/5267.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/7041.jpg") == 0) {
             exposeVals[i] = 0;
             palletVals[i] = 1;
               greyVals[i] = 0;
               blurVals[i] = 1;
              sharpVals[i] = 3;
    //          picValue[i] = 2.35024;
    //   Blur: 3
    //   Exposure: 0
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/7398.jpg") == 0) {
             exposeVals[i] = 8;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 8
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/9017.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 1;
               greyVals[i] = 6;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/10621.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/11086.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 1;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/11663.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 1;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/13055.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 1;
               greyVals[i] = 8;
               blurVals[i] = 4;
              sharpVals[i] = 8;
    //          picValue[i] = 8.55598;
    //   Blur: 8
    //   Exposure: 3
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/13063.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 1;
               greyVals[i] = 4;
               blurVals[i] = 2;
              sharpVals[i] = 8;
    //          picValue[i] = 9;
    //   Blur: 8
    //   Exposure: 6
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/15673.jpg") == 0) {
             exposeVals[i] = 0;
             palletVals[i] = 1;
               greyVals[i] = 0;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 7.20526;
    //   Blur: 9
    //   Exposure: 0
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/16148.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/18862.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/19817.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 3;
               blurVals[i] = 1;
              sharpVals[i] = 8;
    //          picValue[i] = 7.79291;
    //   Blur: 8
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/20365.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 3;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 8.85561;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/23173.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 1;
               greyVals[i] = 5;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/23798.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/28221.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 8.85561;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/29021.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/32059.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 2;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/34048.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 1;
               greyVals[i] = 5;
               blurVals[i] = 2;
              sharpVals[i] = 7;
    //          picValue[i] = 8.19692;
    //   Blur: 7
    //   Exposure: 4
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/35045.jpg") == 0) {
             exposeVals[i] = 0;
             palletVals[i] = 1;
               greyVals[i] = 0;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 7.20526;
    //   Blur: 9
    //   Exposure: 0
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/35089.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 1;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 8.85561;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/35204.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 2;
               blurVals[i] = 9;
              sharpVals[i] = 6;
    //          picValue[i] = 9;
    //   Blur: 6
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/1299.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 6;
    //          picValue[i] = 8.10834;
    //   Blur: 6
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/1324.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/1463.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/2823.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/2876.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/3309.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/6951.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 2;
              sharpVals[i] = 4;
    //          picValue[i] = 5.62976;
    //   Blur: 4
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/7325.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/9407.jpg") == 0) {
             exposeVals[i] = 10;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 10
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/10257.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/15596.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 5;
    //          picValue[i] = 6.38791;
    //   Blur: 5
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/16789.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/16893.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 7;
    //          picValue[i] = 8.5297;
    //   Blur: 7
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/19619.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/20076.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/20346.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/21611.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/23285.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/25118.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/25203.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/25509.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 8;
    //          picValue[i] = 8.89731;
    //   Blur: 8
    //   Exposure: 3
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/27357.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/27868.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/29032.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/32461.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/1081.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/1311.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/2859.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 4;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/3639.jpg") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/4598.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/5421.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/6013.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/10651.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/13394.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 8;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/13712.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 9;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/14286.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/15099.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 5;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/15714.jpg") == 0) {
             exposeVals[i] = 11;
             palletVals[i] = 7;
               greyVals[i] = 9;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/19202.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/19663.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 5;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/21615.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/22488.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 8;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/24307.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/27223.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 4;
               greyVals[i] = 2;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/29302.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/32872.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/33637.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/34569.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/34656.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_training/35687.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/2598.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 1;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/2699.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/6035.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 7;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/6898.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 5;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/9580.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/13384.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 1;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/13553.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/15689.jpg") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/15995.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/18432.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 1;
               greyVals[i] = 9;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/18707.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 7;
               greyVals[i] = 7;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/21600.jpg") == 0) {
             exposeVals[i] = 0;
             palletVals[i] = 1;
               greyVals[i] = 1;
               blurVals[i] = 9;
              sharpVals[i] = 7;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/21997.jpg") == 0) {
             exposeVals[i] = 9;
             palletVals[i] = 7;
               greyVals[i] = 9;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/22183.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 4;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/22955.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/23460.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/23954.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 0;
              sharpVals[i] = 8;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/24865.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 8;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/26263.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 4;
               greyVals[i] = 3;
               blurVals[i] = 2;
              sharpVals[i] = 8;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/27713.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 4;
              sharpVals[i] = 7;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/28751.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 9;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/29501.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 9;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/29971.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 3;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/30369.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 5;
              sharpVals[i] = 5;
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/33069.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    }

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_6219832_335762c361_b.jpg") == 0) {
             exposeVals[i] = 8;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 3.9;
    //   Blur: 3
    //   Exposure: 7
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_7620245_0255136806_b.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 4;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 6
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_51321909_2dbba9e35e_o.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 0.6;
    //   Blur: 0
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_apple-tree-2.jpg") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 1.5;
    //   Blur: 1
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_BMW-Z8.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 7.1;
    //   Blur: 5
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_Cowandcalf20.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 5.4;
    //   Blur: 4
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_99.01.violin.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 1;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 5.4;
    //   Blur: 4
    //   Exposure: 1
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_000394_l.jpg") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 5.4;
    //   Blur: 4
    //   Exposure: 7
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_21331105_32634c8e0c_b.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 1;
               greyVals[i] = 3;
               blurVals[i] = 2;
              sharpVals[i] = 6;
    //          picValue[i] = 2.6;
    //   Blur: 2
    //   Exposure: 3
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_51382800_5b257b7196_o.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 1;
               greyVals[i] = 9;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 1.5;
    //   Blur: 1
    //   Exposure: 6
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_56321495_382f0c36f8_o.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 0;
              sharpVals[i] = 5;
    //          picValue[i] = 0.6;
    //   Blur: 0
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_F1000005.jpg") == 0) {
             exposeVals[i] = 8;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 2.6;
    //   Blur: 2
    //   Exposure: 8
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_8362383_76855a026d_o.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 1;
               greyVals[i] = 7;
               blurVals[i] = 0;
              sharpVals[i] = 9;
    //          picValue[i] = 0.6;
    //   Blur: 0
    //   Exposure: 6
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_26028292_d2b7a32e1c_o.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 7.1;
    //   Blur: 5
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_56391069_f224b7cfdc_o.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 3;
              sharpVals[i] = 5;
    //          picValue[i] = 3.9;
    //   Blur: 3
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_59680439_3093a00838_o.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 4;
              sharpVals[i] = 4;
    //          picValue[i] = 5.4;
    //   Blur: 4
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_cow-and-coastal-mountains-70.4.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 5.4;
    //   Blur: 4
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_NYC_New_York_Liberty_Statue_b.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 1.5;
    //   Blur: 1
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_005 Statue of Liberty.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 2.6;
    //   Blur: 2
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_1294081_bdf11afec3_o.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 2.6;
    //   Blur: 2
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_30156988_73ccdb9b53_b.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_30250725_6554321391_o.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 7
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_56904923_b790a0b060_o.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 2;
               blurVals[i] = 9;
              sharpVals[i] = 6;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_57070363_5529a4ae88_o.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 2;
              sharpVals[i] = 9;
    //          picValue[i] = 2.6;
    //   Blur: 2
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/46_57854854_2f6dcdf3a1_b.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 3;
              sharpVals[i] = 3;
    //          picValue[i] = 3.9;
    //   Blur: 3
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/47_rose-2.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 9;
              sharpVals[i] = 2;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/48_44661953_96ccc6caf5_o.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 8;
              sharpVals[i] = 3;
    //          picValue[i] = 9;
    //   Blur: 8
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/49_Roseblanchelisererose800.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 1;
              sharpVals[i] = 4;
    //          picValue[i] = 1.5;
    //   Blur: 1
    //   Exposure: 6
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/51_pickingapple044.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 7;
               blurVals[i] = 7;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 7
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/52_AppleEgremontRusset.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 1;
              sharpVals[i] = 4;
    //          picValue[i] = 1.5;
    //   Blur: 1
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/53_Apple6.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 6
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/54_CodlingMothBite7K.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 3;
              sharpVals[i] = 2;
    //          picValue[i] = 3.9;
    //   Blur: 3
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/58_00.07.eli.violin.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 9;
              sharpVals[i] = 5;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/59_3530244_a6924d938c_b.jpg") == 0) {
             exposeVals[i] = 7;
             palletVals[i] = 7;
               greyVals[i] = 2;
               blurVals[i] = 2;
              sharpVals[i] = 2;
    //          picValue[i] = 2.6;
    //   Blur: 2
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/60_VictoriaPlayingViolin.jpg") == 0) {
             exposeVals[i] = 2;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 9;
              sharpVals[i] = 5;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/61_playingviolinedited.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 1;
               greyVals[i] = 2;
               blurVals[i] = 3;
              sharpVals[i] = 5;
    //          picValue[i] = 3.9;
    //   Blur: 3
    //   Exposure: 2
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/62_01-ILikeThisBMW.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/63_3-bmw318i-991.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 6;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 6
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/64_BMWC1.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 1;
              sharpVals[i] = 9;
    //          picValue[i] = 1.5;
    //   Blur: 1
    //   Exposure: 6
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/65_9744484_90e44a2890_o.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 7;
               greyVals[i] = 5;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 3.9;
    //   Blur: 3
    //   Exposure: 4
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/65_Statue of Liberty BZs.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 4;
              sharpVals[i] = 3;
    //          picValue[i] = 5.4;
    //   Blur: 4
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/66_statue-of-liberty 12.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 4;
               greyVals[i] = 9;
               blurVals[i] = 3;
              sharpVals[i] = 7;
    //          picValue[i] = 3.9;
    //   Blur: 3
    //   Exposure: 5
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/67_1333234_7510a7b757_o.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 4;
               blurVals[i] = 4;
              sharpVals[i] = 9;
    //          picValue[i] = 5.4;
    //   Blur: 4
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/67_Statue of Liberty (1).jpg") == 0) {
             exposeVals[i] = 0;
             palletVals[i] = 1;
               greyVals[i] = 0;
               blurVals[i] = 4;
              sharpVals[i] = 4;
    //          picValue[i] = 5.4;
    //   Blur: 4
    //   Exposure: 0
    //   Color: 1
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/68_DSC04343-cow.jpg") == 0) {
             exposeVals[i] = 6;
             palletVals[i] = 7;
               greyVals[i] = 3;
               blurVals[i] = 5;
              sharpVals[i] = 9;
    //          picValue[i] = 7.1;
    //   Blur: 5
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/68_statue-of-liberty 2.jpg") == 0) {
             exposeVals[i] = 3;
             palletVals[i] = 4;
               greyVals[i] = 8;
               blurVals[i] = 4;
              sharpVals[i] = 1;
    //          picValue[i] = 5.4;
    //   Blur: 4
    //   Exposure: 4
    //   Color: 4
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/69_36370488_c5e200c8f6_o.jpg") == 0) {
             exposeVals[i] = 5;
             palletVals[i] = 7;
               greyVals[i] = 6;
               blurVals[i] = 9;
              sharpVals[i] = 9;
    //          picValue[i] = 9;
    //   Blur: 9
    //   Exposure: 5
    //   Color: 7
    }
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/70_CowMoose.jpg") == 0) {
             exposeVals[i] = 4;
             palletVals[i] = 4;
               greyVals[i] = 5;
               blurVals[i] = 3;
              sharpVals[i] = 9;
    //          picValue[i] = 3.9;
    //   Blur: 3
    //   Exposure: 4
    //   Color: 4
    }


    else return false;
    return true;

}

#endif // ALGORITHMPRESETS_H
