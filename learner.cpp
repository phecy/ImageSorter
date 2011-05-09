#include "learner.h"

#include "dlib/svm.h"

using namespace std;
using namespace dlib;

Learner::Learner(string relationName)
{
}
// The contents of this file are in the public domain. See LICENSE_FOR_EXAMPLE_PROGRAMS.txt
/*
    This is an example illustrating the use of the epsilon-insensitive support vector
    regression object from the dlib C++ Library.

    In this example we will draw some points from the sinc() function and do a
    non-linear regression on them.
*/

#include <iostream>
#include <vector>

#include "dlib/svm.h"

#include "vimage.h"

using namespace std;
using namespace dlib;

// Here is the sinc function we will be trying to learn with the svr_trainer
// object.
double sinc(double x)
{
    if (x == 0)
        return 1;
    return sin(x)/x;
}

void Learner::learn(std::vector<VImage*> images) {
    int numImages = images.size();
    if(numImages == 0) return;
    int numAttributes = images[0]->getRanks().size();

    // Samples will be NUM-ATTR dimensional column vectors.
    typedef matrix<float,0,1> sample_type;

    // Default good results without fiddling
    typedef radial_basis_kernel<sample_type> kernel_type;

    // Make attribute and label vectors
    std::vector<sample_type> samples;
    std::vector<float> targets;

    // Create samples and label them
    sample_type m;
    m.set_size(numAttributes);
    for (int i=0; i<numImages; ++i)
    {
        for(int attr=0; attr<numAttributes; ++attr)
            m(attr) = images[i]->getRanks()[attr].second;

        samples.push_back(m);
        targets.push_back(images[i]->getRanks()[0].second);
    }

    // Now setup a SVR trainer object.  It has three parameters, the kernel and
    // two parameters specific to SVR.
    svr_trainer<kernel_type> trainer;
    trainer.set_kernel(kernel_type(0.1));

    // This parameter is the usual regularization parameter.  It determines the trade-off
    // between trying to reduce the training error or allowing more errors but hopefully
    // improving the generalization of the resulting function.  Larger values encourage exact
    // fitting while smaller values of C may encourage better generalization.
    trainer.set_c(10);

    // Epsilon-insensitive regression means we do regression but stop trying to fit a data
    // point once it is "close enough" to its target value.  This parameter is the value that
    // controls what we mean by "close enough".  In this case, I'm saying I'm happy if the
    // resulting regression function gets within 0.001 of the target value.
    trainer.set_epsilon_insensitivity(0.001);

    // Now do the training and save the results
    decision_function<kernel_type> df = trainer.train(samples, targets);

    // now we output the value of the sinc function for a few test points as well as the
    // value predicted by SVR.
    for(int attr=0; attr<numAttributes; ++attr) {
        m(attr) = images[0]->getRanks()[attr].second;
    }
    cout << m(0) << "   " << df(m) << endl;

    // The first column is the true value of the sinc function and the second
    // column is the output from the SVR estimate.

    // We can also do 5-fold cross-validation and find the mean squared error.  Note that
    // we need to randomly shuffle the samples first.  See the svm_ex.cpp for a discussion of
    // why this is important.
    randomize_samples(samples, targets);
    cout << "MSE: "<< cross_validate_regression_trainer(trainer, samples, targets, 5) << endl;
}
