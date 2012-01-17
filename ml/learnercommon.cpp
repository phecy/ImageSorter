#include <cstdlib>
#include <iostream>
#include <fstream>
#include <istream>

#include "learnercommon.h"
#include "dirent.h"

string LearnerCommon::findExistingFile(string ext) {
    string filename = DEFAULT_SVR_FILENAME;

    ifstream ifile(filename.c_str());
    if (!ifile) {
        // Not default. Try to find any.
        filename = LearnerCommon::findFiletype(ext);
        if(filename == "") {
            cerr << "No training data found!"
                 << "Please train the app first.\n"
                 << "Files belong in "
                 << DEFAULT_LEARN_DIR << endl;
            exit(1);
        }
    }
    return filename;
}

string LearnerCommon::findFiletype(string ext) {
    int extSize = ext.size();

    DIR *dir = opendir (DEFAULT_LEARN_DIR);
    if (dir == NULL) return "";

    struct dirent *entry;
    while ((entry = readdir (dir)) != NULL) {
        string fn(entry->d_name);
        int fnsize = fn.size();

        if(fnsize > extSize
           && fn.substr(fnsize-extSize) == ext) {
            closedir(dir);
            return DEFAULT_LEARN_DIR + fn;
        }
    }
    closedir (dir);
    return "";
}
