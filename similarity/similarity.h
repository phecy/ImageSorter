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

#ifndef SIMILARITY_H
#define SIMILARITY_H

#include <map>
#include "time.h"
#include "gaussian.h"
#include "histogram.h"
#include "vimage.h"

using namespace std;


class Similarity {
public:
    Similarity(vector<VImage*> allImages);

    // Returns the similarity rank between the two images
    VImage* getSimilarity(VImage* one, VImage* two);

private:
    // Index [i,j] holds the similarity between vimages
    // i and j. A value of -1 indicates the similarity has
    // not been determined yet.
    vector<vector<float> > similarityMatrix;

    // Runs each of the similarity modules and returns their result
    float calculateSimilarity(VImage* one, VImage* two);

    // Adds the ranking to the matrix at [one][two] and [two][one]
    void addSimilarityRating(VImage* one, VImage* two, float ranking);

    // Similarity detection modules
    SimilarityTime* timed;
    SimilarityGaussian* gaussian;
    SimilarityHistogram* histogram;
};

#endif
