Image Sort

This is a program written in C++ using QT Creator. The aim of this program is
pass the program a list of pictures via the command line and it will take and
sort the images, rating each image on a scale 0-9 based on the catagories of:
level of blur, pallet of colors in the image, level of exposer of the image, 
and the grey scale the image has. Duplicates will be given a value of zero
as well.

To run this code, you must have the pictures in the directory of the program,
and you must pass in each file name of the target pictures. As of now the
program will run the test on up to 425 pictures at a time. If you would like
to have the program only give you results of say the top 100 images, you can
go in and manually change the amount of target images which is on line 138
in the main.cpp file. On lines 60-63 of main.cpp you can also change the
weight that each criteria has on rating the image so you can give more or
less emphasis to each catagorie. After you run the program there will be two
files of results name "results.txt" and "results_expanded.txt". These two
files will list the over all ratings and if you would like to see the ratings
in more detail the expanded results file will tell you this information as
well.

To run this code you must also use QTcreator.
