class Kurtosis {
// protected:
//     /**Fourth Moment on which this statistic is based */
//     FourthMoment moment;
// 
//     /** 
//      * Determines whether or not this statistic can be incremented or cleared.
//      * 
//      * Statistics based on (constructed from) external moments cannot
//      * be incremented or cleared.
//     */
//     bool incMoment;
// 
//     /**
//      * Construct a Kurtosis
//      */
//     Kurtosis();
// 
//     /**
//      * Construct a Kurtosis from an external moment
//      * 
//      * @param m4 external Moment
//      */
//     Kurtosis(const FourthMoment& m4);
// 
// public:
//     /**
//      * @see org.apache.commons.math.stat.descriptive.StorelessUnivariateStatistic#increment(double)
//      */
//     void increment(final double d);
// 
//     double getResult();
// 
//     void clear();
// 
//     long getN();
    
    /* UnvariateStatistic Approach  */

    /**
     * Returns the kurtosis of the entries in the specified portion of the
     * input array.  
     * <p>
     * See {@link Kurtosis} for details on the computing algorithm.
     * <p>
     * Throws <code>IllegalArgumentException</code> if the array is null.
     * 
     * @param values the input array
     * @param begin index of the first array element to include
     * @param length the number of elements to include
     * @return the kurtosis of the values or Double.NaN if length is less than
     * 4
     * @throws IllegalArgumentException if the input array is null or the array
     * index parameters are not valid
     */
public:
    static double calcKurtosis(const std::vector<double>& values);
};
