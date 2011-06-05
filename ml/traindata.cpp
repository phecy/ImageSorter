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
            hashnum *= (*feat_i) * (*feat_i);
            hashnum *= img_i->groundTruth;
        }
        for(feat_i  = img_i->highLevelFeatures.begin();
            feat_i != img_i->highLevelFeatures.end();
            ++feat_i) {
            hashnum *= (*feat_i) * (*feat_i);
            hashnum *= img_i->groundTruth;
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
map <string, vector<double> > TrainData::getCSVData()
{
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

    int key_arr[NUM_KEYWORDS];
    char *array[NUM_ROWS][NUM_COLUMNS];
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

        while (tmp != NULL)
        {
               // printf("%d: tmp %s keyword %s\n", field_cnt, tmp, keywords_arr[keyword_cnt]);
                if (!strcmp(tmp, " Input.image ") || !strncmp(tmp," Answer.", 8))
                {
                 //       printf("--------keyword = %s\n", keywords_arr[keyword_cnt]);
                        key_arr[keyword_cnt] = field_cnt;
                        keyword_cnt++;
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

        for (int i=0; i<row; i++)
        {
            string t = array[i][key_arr[0]];
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

        for (int i=0; i<row; i++)
        {
            for (int j=1; j<keyword_cnt; j++)
            {
                string t = array[i][key_arr[0]];
                t = strrchr(t.c_str(), '/')+1;

                double val = atoi(array[i][key_arr[j]].c_str());
                vector<pair<double, int> > row = highlevel[t];
                row[j].first += val;
                row[j].second++;
            }
        }
/*

        for (int i=0; i<NUM_COLUMNS; i++)
        {
                if (!strcmp(array[0][i],key_arr[key_cnt].word)) {key_arr[key_cnt].position = i; key_cnt++;}
                if (key_cnt == NUM_KEYWORDS) break; // we got them all
        }

        for (int i=0; i<NUM_KEYWORDS; i++)
                printf("%s  %d \n", key_arr[i].word, key_arr[i].position);

        // set them all to zero
        for (int j=0; j<NUM_ROWS; j++)
        {
                for (int i=0; i<NUM_KEYWORDS-1; i++)
                {
                        output[j].numeric_fields[i] = 0;
                }
        }


        strcpy(output[0].name, array[1][key_arr[0].position]);

        int cnt = 0;
        float blur_sum = 0;
        float qual_sum = 0;
        int output_row_cnt = 0;
        float val = 0;
        float qual_val = 0;
        for (int i=1; i<row; i++)
        {
                // assuming first interesting field gona be image name
                if (!strcmp(array[i][key_arr[0].position], output[output_row_cnt].name))
                // equal
                {
                        for (int j=1; j<NUM_KEYWORDS; j++)
                        {
                                sscanf(array[i][key_arr[j].position], "%f", &val);
                                output[output_row_cnt].numeric_fields[j-1] += val; // leapes otam lifney
                                cnt++;  // have to remember how many of them we got, to calc the avg later
                        }
                }
                else
                // not equal, starting a new image
                {
                        for (int j=1; j<NUM_KEYWORDS; j++)
                        {
                                output[output_row_cnt].numeric_fields[j-1] = (output[output_row_cnt].numeric_fields[j-1]/2.)/cnt;
                        }
                        cnt = 0;
                        output_row_cnt++;
                        strcpy(output[output_row_cnt].name, array[i][key_arr[0].position]);
                        for (int j=1; j<NUM_KEYWORDS; j++)
                        {
                                sscanf(array[i][key_arr[j].position], "%f", &val);
                                output[output_row_cnt].numeric_fields[j-1] += val; // leapes otam lifney
                                cnt++;  // have to remember how many of them we got, to calc the avg later
                        }
                }
        }

        printf("==========================================================================================\n");
        for (int i=0; i<output_row_cnt; i++)
        {
                printf("%d: %s,%f,%f\n", i, output[i].name, output[i].numeric_fields[0], output[i].numeric_fields[1]);
        }

        printf("\n\n");
  */
        fclose(pCSVFile);
    }

    // Calc averages
    map <string, vector<double> > averagedVals;
    map <string, vector<pair<double, int> > >::iterator iter;
    for(iter = highlevel.begin(); iter != highlevel.end(); ++iter) {
        vector<pair<double, int> > row = iter->second;
        vector<double> averagedRow;
        for(int i = 0; i < row.size(); ++i) {
            if(row[i].second == 0) averagedRow.push_back(-1);
            else averagedRow.push_back(row[i].first / row[i].second);
        }
        averagedVals[iter->first] = averagedRow;
    }

    return averagedVals;
}
