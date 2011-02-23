#include <QImage>
#include <QDebug>

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include <math.h>

#include "exposure.h"
#include "vimage.h"

using namespace std;

exposure::exposure(){
}

float exposure::expose(VImage *vim) {
    QImage* im = vim->getQImage();
    string imageName = vim->getFilename();

    if (!im) {
        cerr << "Could not load " << imageName << endl;
        exit (1);
    }

    int width=0;
    int height=0;
    int pixels=0;
    int per60[2] ={0,0};
    int per98[2] ={0,0};
    // foreground
    int fg_per60[2] ={0,0};
    int fg_per98[2] ={0,0};
    // background
    int bg_per60[2] ={0,0};
    int bg_per98[2] ={0,0};

    width = im->width();
    height = im->height();
    pixels=width*height;

    // Seperation of "foreground" and background"
    // Stuff in the inner square is "foreground"
    // while everything else is background
    int bg_width_buffer = width *0.1;
    int bg_height_buffer= height*0.1;
    int bg_pixels = 0; // need to count me!
    int fg_pixels = 0;


    int RGB[256][4]; // red is 0, green is 1, blue is 2, and luminosity is 3
    int bg_RGB[256][4];
    int fg_RGB[256][4];
    for (int i=0; i<256; i++){ //Initalize everything
       for (int j=0; j<4; j++){
           RGB[i][j]=0;
            bg_RGB[i][j]=0;
            fg_RGB[i][j]=0;
       }
     }


    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
             int red = qRed (im->pixel (x, y));
             int green = qGreen (im->pixel (x, y));
             int blue = qBlue (im->pixel (x, y));
             RGB[red][0] = RGB[red][0]+1;       //Storing the relative intensities of the R, G, and B values
             RGB[green][1] = RGB[green][1]+1;
             RGB[blue][2]= RGB[blue][2]+1;
             if ( (y<bg_width_buffer) || ( y>(width-bg_width_buffer)) || (x<bg_height_buffer) || ( x>(width-bg_height_buffer)) ) { // if the pixel is in the background
                 bg_RGB[red][0]=bg_RGB[red][0]+1;
                 bg_RGB[green][1]=bg_RGB[green][1]+1;
                 bg_RGB[blue][2]=bg_RGB[blue][2]+1;
                 bg_pixels++;
             }else { // if not in background, it's in the foreground
                 fg_RGB[red][0]=fg_RGB[red][0]+1;
                 fg_RGB[green][1]=fg_RGB[green][1]+1;
                 fg_RGB[blue][2]=fg_RGB[blue][2]+1;
                 fg_pixels=fg_pixels+1;
             }
          }
     }

     float mean = 0;
     float variance = 0;
     float fg_mean=0;
     float bg_mean=0;
     float fg_variance=0;
     float bg_variance=0;
     for (int i=0; i<256; i++){ //calculate the luminosity intensities and the mean
         float lumin= (RGB[i][0]*0.59)+(RGB[i][1]*0.3)+(RGB[i][2]*0.11);
          // ^Note that the luminosity is adjusted to how your eye sees relative color strength
         mean = mean + (i*lumin);
         RGB[i][3]= (int)lumin;
         // Now to do that ^ for the foreground and background
         lumin= (fg_RGB[i][0]*0.59)+(fg_RGB[i][1]*0.3)+(fg_RGB[i][2]*0.11);
         fg_mean= fg_mean + (i*lumin);
         fg_RGB[i][3]=lumin;
         // now background
         lumin= (bg_RGB[i][0]*0.59)+(bg_RGB[i][1]*0.3)+(bg_RGB[i][2]*0.11);
         bg_mean= bg_mean + (i*lumin);
         bg_RGB[i][3]=lumin;
     }
     mean = mean/pixels;
     fg_mean = fg_mean/fg_pixels;
     bg_mean = bg_mean/bg_pixels;

     for (int i=0; i<256; i++){ //calculate the variance
         float x= (((RGB[i][3]*i)-mean)/pixels)*(((RGB[i][3]*i)-mean)/pixels);
         variance = variance + x;
         // foreground
         x= (((fg_RGB[i][3]*i)-fg_mean)/fg_pixels)*(((fg_RGB[i][3]*i)-fg_mean)/fg_pixels);
         fg_variance = fg_variance+x;
         // background
         x= (((bg_RGB[i][3]*i)-bg_mean)/bg_pixels)*(((bg_RGB[i][3]*i)-bg_mean)/bg_pixels);
         bg_variance = bg_variance+x;
     }

      int pixelPercent_high = pixels; //This will aid in finding the percentile distribution
      int pixelPercent_low = pixels;
      bool per60found_high=false;//flags indicating if the percentile has been found
      bool per98found_high=false;
      bool per60found_low=false;
      bool per98found_low=false;
      // repeat for the foreground and background
      int fg_pixelPercent_high = fg_pixels; //This will aid in finding the percentile distribution
      int fg_pixelPercent_low = fg_pixels;
      bool fg_per60found_high=false;//flags indicating if the percentile has been found
      bool fg_per98found_high=false;
      bool fg_per60found_low=false;
      bool fg_per98found_low=false;

      int bg_pixelPercent_high = bg_pixels; //This will aid in finding the percentile distribution
      int bg_pixelPercent_low = bg_pixels;
      bool bg_per60found_high=false;//flags indicating if the percentile has been found
      bool bg_per98found_high=false;
      bool bg_per60found_low=false;
      bool bg_per98found_low=false;

      for (int i=0; i<255; i++){ //calculate the percentiles
          pixelPercent_low=pixelPercent_low-(RGB[i][3]);    // I am working the distribution curve from both sides
          pixelPercent_high=pixelPercent_high-(RGB[255-i][3]); // So need to subtract correct amount form each "side"
                                                     //     of the curve (each end of the RGB values).
          // repeat for foreground
          fg_pixelPercent_low=fg_pixelPercent_low-(fg_RGB[i][3]);
          fg_pixelPercent_high=fg_pixelPercent_high-(fg_RGB[255-i][3]);
          // repeat for background
          bg_pixelPercent_low=bg_pixelPercent_low-(bg_RGB[i][3]);
          bg_pixelPercent_high=bg_pixelPercent_high-(bg_RGB[255-i][3]);

          if((pixelPercent_high<=(pixels*.7))&&!per60found_high) {    // Checks if the "60th" (30th on one half of the curve) percentile has been found
              per60[1]=255-i;
              per60found_high=true;  //if found set the flag
           }
          if((pixelPercent_low<=(pixels*.7))&&!per60found_low) {  // repeat for low
              per60[0]=i;
              per60found_low=true;  //if found set the flag
           }
          if((pixelPercent_high<=(pixels*.98))&&!per98found_high) {    // Checks if the "98th" (98th on one HALF of the curve) percentile has been found
              per98[1]=255-i;
              per98found_high=true;  //if found set the flag
           }
          if((pixelPercent_low<=(pixels*.98))&&!per98found_low) {  // repeat for low
              per98[0]=i;
              per98found_low=true;  //if found set the flag
           }
          // repeat for foreground
          if((fg_pixelPercent_high<=(fg_pixels*.7))&&!fg_per60found_high) {    // Checks if the "60th" (30th on one half of the curve) percentile has been found
              fg_per60[1]=255-i;
              fg_per60found_high=true;  //if found set the flag
           }
          if((fg_pixelPercent_low<=(fg_pixels*.7))&&!fg_per60found_low) {  // repeat for low
              fg_per60[0]=i;
              fg_per60found_low=true;  //if found set the flag
           }
          if((fg_pixelPercent_high<=(fg_pixels*.98))&&!fg_per98found_high) {    // Checks if the "98th" (98th on one HALF of the curve) percentile has been found
              fg_per98[1]=255-i;
              fg_per98found_high=true;  //if found set the flag
           }
          if((fg_pixelPercent_low<=(fg_pixels*.98))&&!fg_per98found_low) {  // repeat for low
              fg_per98[0]=i;
              fg_per98found_low=true;  //if found set the flag
           }
          // repeat for background
          if((bg_pixelPercent_high<=(bg_pixels*.7))&&!bg_per60found_high) {    // Checks if the "60th" (30th on one half of the curve) percentile has been found
              bg_per60[1]=255-i;
              bg_per60found_high=true;  //if found set the flag
           }
          if((bg_pixelPercent_low<=(bg_pixels*.7))&&!bg_per60found_low) {  // repeat for low
              bg_per60[0]=i;
              bg_per60found_low=true;  //if found set the flag
           }
          if((bg_pixelPercent_high<=(bg_pixels*.98))&&!bg_per98found_high) {    // Checks if the "98th" (98th on one HALF of the curve) percentile has been found
              bg_per98[1]=255-i;
              bg_per98found_high=true;  //if found set the flag
           }
          if((bg_pixelPercent_low<=(bg_pixels*.98))&&!bg_per98found_low) {  // repeat for low
              bg_per98[0]=i;
              bg_per98found_low=true;  //if found set the flag
           }
       }


      // Using the numbers to calculate rank
      double sumLumLowEdge=0;    // The "lower" range of luminosity in the image (dark)
      double sumLumHighEdge=0;   // The "upper" range of luminosity in the image (bright)
      // foreground
      double fg_sumLumLowEdge=0;
      double fg_sumLumHighEdge=0;
      // background
      double bg_sumLumLowEdge=0;
      double bg_sumLumHighEdge=0;

      for (int i=0; i<5; i++){  // The edges are the summation of the 5 values in from the edge
          sumLumLowEdge = sumLumLowEdge+ (RGB[i][3]);
          sumLumHighEdge = sumLumHighEdge+ (RGB[255-i][3]);
          // foreground
          fg_sumLumLowEdge = fg_sumLumLowEdge+ (fg_RGB[i][3]);
          fg_sumLumHighEdge = fg_sumLumHighEdge+ (fg_RGB[255-i][3]);
          // background
          bg_sumLumLowEdge = bg_sumLumLowEdge+ (bg_RGB[i][3]);
          bg_sumLumHighEdge = bg_sumLumHighEdge+ (bg_RGB[255-i][3]);
      }




      // These checkpoints and values were found from surveying 71 images specially picked to be good (or rahter bad)
      // examples of extreme exposure problems and comparing many different measurements.
      // It started with the 60th, 70th, 80th, 90th, 95th, 98th, and 99th percentiles,
      // and the histogram of Red, Green, Blue, Luminosity, and grey.  Also the mean and varaince.
      //
      // I chose to use the edges of the luminosity because it represents highlight and
      // shadow clipping very well because it's adjusted to the relative percieved brightness of the human visual system.
      //
      // Where the 60th percentile is a good measure of how the luminosity is in the middle (ie, a low value means that
      // it's a fairly even distribution, and a high value means that it has a high peak).  The 98th percentile
      // is a good indication of how wide the "range" of the luminosity is.  I sometimes use it instead of the
      // mean and variance when it seems to work better.
      //
      // Again, the specific numbers were determined by my trial set of images.  Run on a set of 196 images that
      // were ranked by workers on mechanical turk with some fine-tuning by me.

      //cout<<((per60[0]>65)&&(!((per98[0]==0)&&(sumLumLowEdge<0.045))))<<"\n";


      double clipping = abs(sumLumHighEdge+sumLumLowEdge); //note this measurement is the total highlights AND shadow clipping
      clipping = clipping/pixels;
      // foreground
      double fg_clipping = abs(fg_sumLumHighEdge+fg_sumLumLowEdge);
      fg_clipping=fg_clipping/fg_pixels;
      // background
      double bg_clipping = abs(bg_sumLumHighEdge+bg_sumLumLowEdge);
      bg_clipping=bg_clipping/bg_pixels;

      sumLumLowEdge = sumLumLowEdge/pixels;
      sumLumHighEdge = sumLumHighEdge/pixels;
      fg_sumLumHighEdge = fg_sumLumHighEdge/fg_pixels;
      bg_sumLumHighEdge = bg_sumLumHighEdge/bg_pixels;
      fg_sumLumLowEdge = fg_sumLumLowEdge/fg_pixels;
      bg_sumLumLowEdge = bg_sumLumLowEdge/bg_pixels;



      // now to output the results
      //Creates a .txt file that stores the expanded results.


      ofstream resultsExpanded;
      resultsExpanded.precision(6);
      resultsExpanded.open ("exposure_histograms.csv", ios_base::app);
      resultsExpanded << imageName << endl;
      resultsExpanded << "Foreground,"<<fg_pixels<<endl;
      int running=0;
      double running_total=0;
      double total_by_pixels=0;
      for (int i=1; i<256; i++){
          running ++;
          running_total = running_total + fg_RGB[i][3];
          if (running ==5) {
              total_by_pixels = (running_total/fg_pixels);
              resultsExpanded << total_by_pixels << ",";
              running=0;
              running_total=0;
          }
      }
      resultsExpanded << endl;
      resultsExpanded << "Background,"<<bg_pixels<<endl;
      running=0;
      running_total=0;
      for (int i=1; i<256; i++){
          running ++;
          running_total = running_total + bg_RGB[i][3];
          if (running ==5) {
              total_by_pixels = running_total/bg_pixels;
              resultsExpanded << total_by_pixels << ",";
              running=0;
              running_total=0;
          }
      }
      resultsExpanded << endl;


      resultsExpanded.close();

      float rating_out[3];






      float mean_in=0;
      float variance_in=0;
      double sumLumHighEdge_in=0;
      double sumLumLowEdge_in=0;
      int per98_in[2]={0,0};
      int per60_in[2]={0,0};
      float clipping_in=0;



      for(int i=0; i<1; i++) {
          // First set up the variables for the overall image, foreground and background
          if (i==0) {
              mean_in = mean;
              variance_in=variance;
              sumLumHighEdge_in=sumLumHighEdge;
              sumLumLowEdge_in=sumLumLowEdge;
              per98_in[0]=per98[0];
              per98_in[1]=per98[1];
              per60_in[0]=per60[0];
              per60_in[1]=per60[1];
              clipping_in=clipping;

          }
          if (i==1) {
              mean_in=fg_mean;
              variance_in=fg_variance;
              sumLumHighEdge_in=fg_sumLumHighEdge;
              sumLumLowEdge_in=fg_sumLumLowEdge;
              per98_in[0]=fg_per98[0];
              per98_in[1]=fg_per98[1];
              per60_in[0]=fg_per60[0];
              per60_in[1]=fg_per60[1];
              clipping_in=fg_clipping;
          }
          if (i==2) {
              mean_in=bg_mean;
              variance_in=bg_variance;
              sumLumHighEdge_in=bg_sumLumHighEdge;
              sumLumLowEdge_in=bg_sumLumLowEdge;
              per98_in[0]=bg_per98[0];
              per98_in[1]=bg_per98[1];
              per60_in[0]=bg_per60[0];
              per60_in[1]=bg_per60[1];
              clipping_in=bg_clipping;
          }

          // First we want to run through the foreground
          // Then we will repeat for the background
          // Foreground raitng will have more of an impact than background
          // But additionally, the amount of contrast between the foreground and background will be taken into account
          // to help catch more difficult cases of for example an isolated thing on a white background that is
          // an otherwise good image.
          // Foreground
          // First check
          // Super dark images
          if (fg_mean < 10) {rating_out[i]= 1; continue;} // Image is super dark
          if (fg_mean < 20) {rating_out[i]= 1.3; continue;} // Image is super dark (guess)
          if (fg_mean < 30) {rating_out[i]= 1.8; continue;} // Image is dark (guess)
          if (fg_mean < 45) {
              if (fg_per98[1]<100) {rating_out[i]= 1.3; continue;}  // Dark without much bright
              if (fg_per98[1]<165)  {rating_out[i]= 2.5; continue;} // A bit more light, but still very dark
          }
          if (fg_mean < 80) {
              if (fg_clipping<0.01) {
                  if (fg_per98[1]<204) {rating_out[i]= 3.4; continue;}
                  else {rating_out[i]= 4; continue;}
              } else { // for the other possible clippings
                  if (fg_sumLumLowEdge<0.07) {
                      float linear_scale = (0.16722)*per60[1]-7.4731; // Found linear line of best fit for samples.  Higher per60 is better ranking
                      {rating_out[i]= linear_scale; continue;}
                  } else {rating_out[i]= 3.5; continue;} // A generic catch :C
              }

          }
          if (fg_mean < 100) { // For this we will use a quartic function found to strongly fit the sample images
              // of the form rating=ax^4+bx^3+cx^2+dx+e
              double a = -0.000000152497;
              double b = -0.00004548126;
              double c = -0.0061893889;
              double d = -0.3566412157;
              double e = -3.404030625;
              double x = fg_mean - fg_per98[1];
              double quad_scale = a*pow(x,4); // first term
              quad_scale = quad_scale + b*pow(x,3); //second term
              quad_scale = quad_scale + c*pow(x,2); // third term
              quad_scale = quad_scale + d*x; // fourth term
              quad_scale = quad_scale + e;

          }

          if (fg_mean < 120) {
              if ((fg_sumLumHighEdge>=0.0013)&&(fg_sumLumHighEdge<=0.06)) {
                  if ((fg_sumLumLowEdge/fg_sumLumHighEdge)>0.05) {
                      if (bg_variance<70) {
                          // linear reationship.  rank=a(bgper60[1])+b
                          double a = 0.0177361285;
                          double b = 6.155509553;
                          double rank =(a*bg_per60[1])+b;
                          rating_out[i]= rank;
                          continue;
                      } else {
                          rating_out[i]=7; //Blearrrgh. This is just the average.  OW, I can't figure out what's going on here
                          continue;
                      }
                  }
                  if (fg_sumLumHighEdge<0.013) { // low sumLumHighEdge values not covered above
                      // another linear realtionship, although this one is actually really loose
                      // rating = a(fg_variance)+b
                      double a = 0.0583631313;
                      double b = 1.622121636;
                      double rank = (a*fg_variance)+b;
                      rating_out[i]= rank;
                      continue;
                  } else { // only have 6 samles here, so not very strong. fg_SumLum high from 0.029-0.054
                      rating_out[i]=7; continue;
                  }
              } // Now to resume the upper half of the fg_sumLumHigh's
              if (fg_sumLumHighEdge>0.06) {
                  if (fg_per60[1]<140){ // need the dark color to be not too  light beause of the excessive shumLumHigh
                      // fg_per60[0]-fg_per98[0] gives an idea of how many "deep" blacks you have
                      if ((fg_per60[0]-fg_per98[0])<50) {rating_out[i]= 5.2; continue;}
                      if ((fg_per60[0]-fg_per98[0])>=50) {rating_out[i]= 7.2; continue;}
                  } else { //otherwise the image is too bright
                      // linear relationship with the amount of dark present (lumLowEdge)
                      double a= 0.0761897532;
                      double b= 1.111251139;
                      float rank = a*fg_per60[0]+b;
                      rating_out[i]= rank;
                      continue;
                  }
              } else {// now the lower half aka all else
                  if (fg_per60[1]<130){
                      // BELARGH. Just resurning an average value here. Only had 7 smaples.
                      {rating_out[i]= 7; continue;}
                  } else { // Image is too light from per60 measure
                      if (fg_variance < 83) {rating_out[i]= 5; continue;}
                      else {rating_out[i]= 6.33; continue;}
                  }
              }
          }
          if (fg_mean <138){
              if (fg_clipping<0.0035){
                  if (fg_sumLumHighEdge>0.0001){
                      // getting lazy again
                      rating_out[i]= 6.3;
                      continue;
                  } else {
                      // still lazy
                      rating_out[i]= 5.05;
                      continue;
                  }
              } else {
                  if (fg_sumLumHighEdge<0.009) {
                      // linear woo
                      double a = 0.0182553102;
                      double b= 8.033712605;
                      float rank = a*(bg_per60[0]-fg_per60[0])+b;
                      rating_out[i]= rank;
                      continue;
                  } else {
                      if ((fg_clipping+bg_clipping>0.45)) { // WAAyyyy too much clipping
                          // but can be saved if there is enough of a pread between the 60th high and low percentiles
                          // again, I'm using a simple line to establish.  More spread=better rating
                          double a = 0.097378768;
                          double b = -0.9268676278;
                          float rank = a*(fg_per60[1]-fg_per60[0])+b;
                          rating_out[i]= rank;
                          continue;
                      }
                      if ((fg_per60[1]-fg_per60[0])<75) {
                          // LAAAZYNESS AVERAGED HERE
                          rating_out[i]= 7.6;
                          continue;
                      } else {
                          // blah blah linear.
                          double a = 75.7988785;
                          double b = 3.694145228;
                          float rank = a*(fg_sumLumHighEdge)+b;
                          if (rank > 9.99) rank = 6; // formula is out of control
                          rating_out[i]= rank;
                          continue;
                      }
                  }
              }
          }

          if (fg_mean<170) {
              // blah this is sorta linear.
              double a = 0.0285132174;
              double b = 4.305769891;
              float rank = a*(fg_per60[0]-fg_per98[0])+b;
              rating_out[i]= rank;
              continue;
          }



          // Gankbanked from orig.
          // note that the following based on a too bright mean is just a guess.
          // based roughly on how the curve workd for the dark.
          if (fg_mean>=230) {rating_out[i]= 1; continue;}
          if(fg_mean>=200) {rating_out[i]= 3; continue;}
          if(fg_mean>=170) {rating_out[i]= 4; continue;}

          rating_out[i]= 6; continue; // anything I may have missed. Everything terrible should already be caught.
                               // That leaves just the average to pretty good values.

          // to catch any funny buisness
          if (rating_out[i]<0) rating_out[i]=0;
          if (rating_out[i]>9) rating_out[i]=9;


          // HERE LIES THE OLD RATING SYSTEM ///////////////////////////////////////////////////////////////////////////////
          //First Check
          //rates the SUPER dark images only
          /*if ((per98_in[0]==0)&&(sumLumLowEdge_in<0.045)){ // Note that the percentiles have 2 dimensions,
          //the value from the left and the value from the right  only necessary to check one because calculated symmetrically.
              if ((per60_in[0]-per98_in[0])< 10)  {rating_out[i]= 1; continue;} // Image is super dark
              if ((per60_in[0]-per98_in[0])< 10)  {rating_out[i]= 1.7; continue;} // Image is super dark, but there's a small area of lighter color in places.  Still a bad image, but not 100%black
              // If you get to a higher percentile difference, that may indicate that the darkness is intentionally aroudn a lighter subject
          }

          //Second Pass- Looking at various means
          if(mean_in<=15) {rating_out[i]= 1; continue;}//this is a VERY dark image
          if(mean_in<=50) {rating_out[i]= 1.5; continue;}// POSSIBLE PROBLEM AREA I don't have a large enough sample of images in this area
          if(mean_in<=100) {
              if (per60_in[0]<20) {rating_out[i]= 3.5; continue;} // This hints towards intentional darkness. Still bad image though.
              if (per60_in[0]<30) {rating_out[i]= 3.2; continue;}
              rating_out[i]= 1.5; continue; // This hints towards unintentional darkness
          }

          if (mean_in<=138){ //This is the middle of the values.  A very centered mean
              // Looking for a good amount of highlighting
              if ((sumLumHighEdge_in >= 0.01) && (sumLumHighEdge_in<=0.025)) {  // it peaks around 0.01-0.02
                  if (sumLumLowEdge_in<0.3) {rating_out[i]= 7; continue;} // Not too much black clipping
                  if (sumLumLowEdge_in<0.4) {rating_out[i]= 5; continue;} // A little too much black
              }
              // 0.00785773 0.157651
              if ((sumLumLowEdge_in > 0.1) && (sumLumLowEdge_in > 0.01)) {rating_out[i]= 2; continue;}// too dark without lightness
              if ((sumLumLowEdge_in > 0.01) && (sumLumLowEdge_in > 0.01)) {rating_out[i]= 3.2; continue;}// too dark without lightness, but lesser

              // below is not well verified ---\/
              if ((variance_in >=70)&&(variance_in<=170)) {rating_out[i]= 9; continue;} //this has a good mean and nice wide base. very good distribution.
              if (variance_in >= 170) {rating_out[i]= 7; continue;} // this has a bitt too much variance.  Not as good focus as ^
          }

          if ((mean_in >138)&&(mean_in<=150)) { // images on the bright side of center
              if (sumLumHighEdge_in<0.0001) {rating_out[i]= 4; continue;}
              if (clipping >=0.15) {rating_out[i]= 4; continue;} // POSSIBLE PROBLEM too many highlights blown
              if (per60_in[0]-per98_in[1]<=30) {rating_out[i]= 5.4; continue;}
              else {rating_out[i]= 6.7; continue;}
              
          }

          

          // note that the following based on a too bright mean is just a guess.
          // based roughly on how the curve workd for the dark.
          if (mean_in>=290) {rating_out[i]= 1; continue;}
          if(mean_in>=200) {rating_out[i]= 3; continue;}

          rating_out[i]= 6; continue; // anything I may have missed. Everything terrible should already be caught.
                               // That leaves just the average to pretty good values.
          */


  }

      /*resultsExpanded.open ("exposure_info.csv", ios_base::app); // put the stuff in a csv file at the end of the file
      resultsExpanded << imageName << ","; // first name the image
      resultsExpanded << rating_out[0]<<","<<rating_out[1]<<","<<rating_out[2]<<"," << fg_variance << "," << bg_variance << "," <<
              fg_mean <<"," << bg_mean << "," << fg_clipping << "," <<
              bg_clipping << "," << fg_sumLumHighEdge << "," << fg_sumLumLowEdge<<"," <<
              bg_sumLumHighEdge << "," << bg_sumLumLowEdge << "," << fg_per60[0] << "," << fg_per60[1] << "," <<
              bg_per60[0]<<","<<bg_per60[1] << "," << fg_per98[0]<<","<<fg_per98[1] << "," << bg_per98[0]<<","<<bg_per98[1] << "," <<
              fg_pixels << "," <<bg_pixels << endl;
      //resultsExpanded << rating_out[0]<<","<<rating_out[1]<<","<<rating_out[2]<<endl;

      resultsExpanded.close();*/


      // stuff for calibrating
      // foreground file
      /*resultsExpanded.open ("exposure_info_fg.csv", ios_base::app); // put the stuff in a csv file at the end of the file
      resultsExpanded << imageName << ","; // first name the image
      resultsExpanded << fg_variance << "," << fg_mean << "," << fg_clipping << "," <<
                    fg_sumLumHighEdge <<"," << fg_sumLumLowEdge << "," << fg_per60[0] << "," << fg_per60[1] << "," <<
                    fg_per98[0] << "," << fg_per98[1] << endl;
      resultsExpanded.close();

      // background file

      resultsExpanded.open ("exposure_info_bg.csv", ios_base::app); // put the stuff in a csv file at the end of the file
      resultsExpanded << imageName << ","; // first name the image
      resultsExpanded << bg_variance << "," << bg_mean << "," << bg_clipping << "," <<
                    bg_sumLumHighEdge <<"," << bg_sumLumLowEdge << "," << bg_per60[0] << "," << bg_per60[1] << "," <<
                    bg_per98[0] << "," << bg_per98[1] << endl;
      resultsExpanded.close();

      resultsExpanded.open ("exposure_info_total.csv", ios_base::app); // put the stuff in a csv file at the end of the file
      resultsExpanded << imageName << ","; // first name the image
      resultsExpanded << variance << "," << mean << "," << clipping << "," <<
                    sumLumHighEdge <<"," << sumLumLowEdge << "," << per60[0] << "," << per60[1] << "," <<
                    per98[0] << "," << per98[1] << endl;
      resultsExpanded.close();
      */

      return rating_out[0];

}
