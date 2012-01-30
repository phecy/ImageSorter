// This code ported from:
// http://www.koders.com/java/
//    fid89952DD842FC3E0E1F313F03B7017D0FE45D8BF3.aspx

/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Computes the Kurtosis of the available values.
 * <p>
 * We use the following (unbiased) formula to define kurtosis:
 *  <p>
 *  kurtosis = { [n(n+1) / (n -1)(n - 2)(n-3)] sum[(x_i - mean)^4] / std^4 } - [3(n-1)^2 / (n-2)(n-3)]
 *  <p>
 *  where n is the number of values, mean is the {@link Mean} and std is the
 * {@link StandardDeviation}
 * <p>
 *  Note that this statistic is undefined for n < 4.  <code>Double.Nan</code>
 *  is returned when there is not sufficient data to compute the statistic.
 * <p>
 * <strong>Note that this implementation is not synchronized.</strong> If 
 * multiple threads access an instance of this class concurrently, and at least
 * one of the threads invokes the <code>increment()</code> or 
 * <code>clear()</code> method, it must be synchronized externally.
 * 
 * @version $Revision: 480440 $ $Date: 2006-11-28 23:14:12 -0800 (Tue, 28 Nov 2006) $
 */


/*
Kurtosis::Kurtosis() {
    incMoment = true;
    moment = new FourthMoment();
}

Kurtosis::Kurtosis(const FourthMoment& m4) {
    incMoment = false;
    this.moment = m4;
}

void Kurtosis::increment(const double d) {
    if (incMoment) {
        moment.increment(d);
    }  else  {
        fprintf(stderr, "Statistics constructed from external moments"
                        "cannot be incremented\n");
        abort();
    }
}

double Kurtosis::getResult() {
    double kurtosis = 0;
    if (moment.getN() > 3) {
        double variance = moment.m2 / (double) (moment.n - 1);
        if (moment.n <= 3 || variance < 10E-20) {
            kurtosis = 0.0;
        } else {
            double n = (double) moment.n;
            kurtosis =
                (n * (n + 1) * moment.m4 -
                        3 * moment.m2 * moment.m2 * (n - 1)) /
                        ((n - 1) * (n -2) * (n -3) * variance * variance);
        }
    } else {
        fprintf(stderr, "Kurtosis not defined for N < 4\n");
        abort();
    }
    return kurtosis;
}

void Kurtosis::clear() {
    if (incMoment) {
        moment.clear();
    } else  {
        fprintf(stderr, "Statistics constructed from external moments"
                        " cannot be cleared");
        abort();
    }
}

long Kurtosis::getN() {
    return moment.getN();
}
*/

#include <cmath>
#include <vector>
#include "util/common.h"
#include "kurtosis.h"
using namespace std;

/* UnvariateStatistic Approach  */
float getMean(const vector<double> value) {
    long double sum = 0;
    for(int i=0; i<value.size(); ++i) {
        sum += value[i];
    }
    
    return (float)(sum / value.size());
}

float getStdev(const vector<double> value, float mean) {
    long double sumDist = 0;
    for(int i=0; i<value.size(); ++i) {
        float dist = value[i] - mean;
        sumDist += dist*dist;
    }

    float avgDist = sumDist / value.size();

    return sqrt(avgDist);
}

/**
 * Returns the kurtosis of the entries in the specified portion of the
 * input array.  
 * See {@link Kurtosis} for details on the computing algorithm.
 * Aborts if the size of values is <4
 * 
 * @param values the input array
 * @return the kurtosis of the values
 */
double Kurtosis::calcKurtosis(const vector<double>& values) {
    // Initialize the kurtosis  
    double kurt = 0;
    int length = values.size();

    if(length < 4) {
        fprintf(stderr, "Number of values must be greater than 3.\n");
        abort();
    }
    
    // Compute the mean and standard deviation
    double mean = getMean(values);
    double stdDev = getStdev(values, mean);
    
    // Sum the ^4 of the distance from the mean divided by the
    // standard deviation
    double accum3 = 0.0;
    for (int i = 0; i < length; ++i) {
        accum3 += pow((values[i] - mean), 4.0);
    }
    accum3 /= pow(stdDev, 4.0d);
    
    // Get N
    double n0 = length;
    
    double coefficientOne =
        (n0 * (n0 + 1)) / ((n0 - 1) * (n0 - 2) * (n0 - 3));
    double termTwo =
        ((3 * pow(n0 - 1, 2.0)) / ((n0 - 2) * (n0 - 3)));
    
    // Calculate kurtosis
    kurt = (coefficientOne * accum3) - termTwo;

    return kurt;
}
