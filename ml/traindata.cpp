#include <sstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "common.h"
#include "traindata.h"

#define CSV_FILE_NAME "all_csv_files.txt"
#define CSV_FILE_NAME_LENGTH 100

TrainData::TrainData()
{
}

double TrainData::getLLFeature(int img_i, int feature_i) {
    return trainingSet.at(img_i).lowLevelFeatures.at(feature_i);
}
double TrainData::getHLFeature(int img_i, int feature_i) {
    return trainingSet.at(img_i).highLevelFeatures.at(feature_i);
}
double TrainData::getGroundTruth(int img_i) {
    return trainingSet.at(img_i).groundTruth;
}
void TrainData::addSample(
        vector<double> lowLevelFeatures,
        vector<double> highLevelFeatures,
        double groundTruth) {

    Features features;
    features.lowLevelFeatures = lowLevelFeatures;
    features.highLevelFeatures = highLevelFeatures;
    features.groundTruth = groundTruth;

    trainingSet.push_back(features);
}

string TrainData::hash() {
    double hashnum=1;

    vector<Features>::iterator img_i;
    vector<double>::iterator feat_i;
    for(img_i=trainingSet.begin(); img_i!=trainingSet.end(); ++img_i) {
        for(feat_i  = img_i->lowLevelFeatures.begin();
            feat_i != img_i->lowLevelFeatures.end();
            ++feat_i) {
            hashnum += (*feat_i) * (*feat_i);
            hashnum += img_i->groundTruth;
        }
        for(feat_i  = img_i->highLevelFeatures.begin();
            feat_i != img_i->highLevelFeatures.end();
            ++feat_i) {
            hashnum += (*feat_i) * (*feat_i);
            hashnum += img_i->groundTruth;
        }
    }

    stringstream hashstream;
    hashstream << "trainset_";
    hashstream << hashnum;

    string hashed = hashstream.str();
    // Magic number 9 is for size of "trainset_"
    hashed = hashed.substr(0, min(24, 9+(int)hashed.size()-1));
    for(unsigned int i=9; i<hashed.size(); ++i) {
        if(hashed[i]=='.') hashed[i] = '-';
        else if(hashed[i]=='+') hashed[i] = char(i%10 + '0');
        else if(hashed[i]=='e') hashed[i] = char(i%10 + '0');
    }

    cout << "Hashed val: " << hashed << endl;
    return hashed;
}

string TrainData::genHashFilename(int hlFeat_i) {
    stringstream s;
    s << DEFAULT_LEARN_DIR;
    s << "hl" << hlFeat_i << "_";
    s << hash() + ".tdat";
    return s.str();
}

#define FILE_EXTENSION "csv"
#define NUM_ROWS	1000
#define NUM_COLUMNS	100
#define NUM_KEYWORDS    30
#define MAX_LINE_LENGTH 1000

#define NUMCOLS 5

typedef struct keyword
{
        string word;
        int abs_position; // column number inside string 2d array
        int relative_position; // column numbers relative to the map structure
} keywordData;


map <string, vector<double> > TrainData::getCSVData()
{
    map < string, pair <int,int> > key_arr;

    FILE *pFileOfFileNames;
    char csv_file_name[CSV_FILE_NAME_LENGTH];

    chdir(DEFAULT_LEARN_DIR);

    char cmd[CMD_LENGTH];
    // create file with csv file names
    sprintf(cmd,"ls *.%s > %s", FILE_EXTENSION, CSV_FILE_NAME);
    system(cmd);

    // open file with .csv files names
    if ( (pFileOfFileNames = fopen(CSV_FILE_NAME,"r")) == NULL)
    {
        fprintf(stderr,"-error: can't open list of names file %s\n",CSV_FILE_NAME);
        exit(1);
    }
    else
        fprintf(stdout,"-list of file names %s was opened okay\n",CSV_FILE_NAME);

//    int key_arr[NUM_KEYWORDS];
    map <string, vector<pair<double, int> > > highlevel;

   // for every csv file loop
   while ( fgets(csv_file_name, CSV_FILE_NAME_LENGTH, pFileOfFileNames) )
   {
         FILE *pCSVFile;
         // open single csv file
         string filename = csv_file_name;
         filename = filename.substr(0, filename.size()-1);
         if ( (pCSVFile = fopen(filename.c_str(),"r")) == NULL)
         {
              fprintf(stderr,"-error: can't open csv file %s ...   skipped... \n",filename.c_str());
              continue;
         }
         else
         {
              fprintf(stdout,"  - %s was read fine\n",csv_file_name);
         }

        char first_line[MAX_LINE_LENGTH];
        fgets(first_line, MAX_LINE_LENGTH, pCSVFile);

        char *pChar = first_line;
        char *prev = first_line;
        pChar++;
        while (*pChar != 0 && *pChar != 10 && *pChar != 12 && *pChar != 13 && pChar)
        {
                if (*pChar == '"') *pChar = ' ';
                prev++;
                pChar++;
        }


        char *tmp;
        tmp = strtok(first_line,";");
        int field_cnt = 0;
        int keyword_cnt = 0;

        // parse the fitrst line to know what keywords do we have and their positions
        while (tmp != NULL)
        {
               // printf("%d: tmp %s keyword %s\n", field_cnt, tmp, keywords_arr[keyword_cnt]);
                // assumption: image name will always come first
                if (!strcmp(tmp, " Input.image "))
                {
                 //       printf("--------keyword = %s\n", keywords_arr[keyword_cnt]);
                        pair<int, int> inputpair;
                        inputpair.first = -1;
                        inputpair.second = field_cnt;

                        key_arr["Input.image"] = inputpair;
                }
                // looking for answer.* fields
                else if (!strncmp(tmp," Answer.", 8))
                {
                    // if already exists in our vector, just update its relative and absolute
                    // positions
                    // otherwise create a new entry, and save the name and the positions
                    if (key_arr.find(tmp) == key_arr.end())
                    {
                        pair<int, int> inputpair;
                        inputpair.first = keyword_cnt;
                        inputpair.second = field_cnt;

                        key_arr[tmp] = inputpair;

                        keyword_cnt++;
                    }
                    else // it already exists! just update the positions
                    {
                        pair<int, int> inputpair = key_arr[tmp];
                        //inputpair.first = keyword_cnt;
                        inputpair.second = field_cnt;
                        key_arr[tmp] = inputpair;

                    }

                }

                tmp = strtok(NULL, ";");
                field_cnt++;
        }


        char it;
        int col = 0;
        int row = 0;
        // char *curr_pos;
        string csv_cell;
        vector<string> csv_row;
        vector<vector<string> > array;

        do
        {
            it = fgetc(pCSVFile);

            if (it == ';')
            // start a new cell (column)
            {
                    col++;

                    // Add string to row, then erase
                    csv_row.push_back(csv_cell);
                    csv_cell = "";

                    // array[row][col] = (char*)malloc(500); // define it later
                    // curr_pos = array[row][col];
            }
            else if (it == '\n')
            {
                    row++;
                    col = 0;

                    // Add string to row, then erase and make new row
                    csv_row.push_back(csv_cell);
                    array.push_back(csv_row);
                    csv_cell = "";
                    csv_row = vector<string>();

                    // array[row][col] = (char*)malloc(500); // define it later
                    // curr_pos = array[row][col];
            }
            else if (it == '"')
            {
                    // ignore it!
            }
            else
            {
                csv_cell += it;
                    // *curr_pos = it;
                    // curr_pos++;
            }
        } while (it != EOF);

    // look how many lines we gonna have in our "big map" the highlevel features
        for (int i=0; i<row; i++)
        {
            string t = array[i][key_arr["Input.image"].second];
            t = strrchr(t.c_str(), '/')+1;
            if (highlevel.end() == highlevel.find(t))  // we didn't find this file name
                                                // have to create a new line in the map
            {
                pair<double, int> defaultpair;
                defaultpair.first = 0;
                defaultpair.second = 0;
                for(int i=0; i<NUMCOLS; ++i)
                    highlevel[t].push_back(defaultpair);
            }
        }

        // Move from CSV Array to Map
        for (int i=0; i<row; i++)
        {
            map<string, pair<int,int> >::iterator key_it;
            for(key_it = key_arr.begin(); key_it != key_arr.end(); ++key_it) {
                string t = array[i][key_arr["Input.image"].second];
                t = strrchr(t.c_str(), '/')+1;

                pair<int, int> indexpair = key_it->second;
                int indexInMapRow = indexpair.first;
                int indexInCSV = indexpair.second;
                if(indexInMapRow == -1) continue;

                double val = atoi(array[i][indexInCSV].c_str());
                vector<pair<double, int> > rowvect = highlevel[t];
                rowvect[indexInMapRow].first += val;
                rowvect[indexInMapRow].second++;
                highlevel[t] = rowvect;
            }
        }

        fclose(pCSVFile);
    }
    chdir("..");

    // Calc averages
    map <string, vector<double> > averagedVals;
    map <string, vector<pair<double, int> > >::iterator iter;
    int numAnswers = key_arr.size() - 1; // -1: exclude Input.image
    for(iter = highlevel.begin(); iter != highlevel.end(); ++iter) {
        vector<pair<double, int> > row = iter->second;
        vector<double> averagedRow;
        for(int i = 0; i < row.size(); ++i) {
            if(i >= numAnswers) continue;
            // If there are answers, average them
            //   and scale from [0,2] to [0,1]
            if(row[i].second == 0) averagedRow.push_back(-1);
            else averagedRow.push_back(row[i].first / (row[i].second*2));
        }
        averagedVals[iter->first] = averagedRow;
    }

    return averagedVals;
}
