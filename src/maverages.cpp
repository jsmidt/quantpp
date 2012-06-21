/**
 ** maverages.hpp - moving averages
 **
 **     
 **
 **
 **********************************************************************/

#include "maverages.hpp" 
#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
using namespace boost::numeric;


// Simple moving average.
void sma(ublas::vector<double> v, ublas::vector<double> &w, size_t N)
{
    for (size_t i = N-1; i < v.size(); i++) { 
        ublas::vector_range<ublas::vector<double> > 
                   vr(v,ublas::range(i-(N-1), i+1));
        w(i) = sum(vr)/vr.size();
    }
}

// Cumulative moving average.
void cma(ublas::vector<double> v, ublas::vector<double> &w)
{
    for (size_t i =0; i < v.size(); i++) { 
        ublas::vector_range<ublas::vector<double> > 
                   vr(v,ublas::range(0, i+1));
        w(i) = sum(vr)/vr.size();
    }
}

// Exponential moving average.
// a= 2/(N+1). N=19 gives a=0.1
void ema(ublas::vector<double> v, ublas::vector<double> &w, int N)
{
    for (size_t i = 9; i < v.size(); i++) {
        //wrote if statement this way so that it won't have to skip over first
        //case everytime. If there is a faster way let me know
        if (i > 9) {
            w(i) = w(i-1) + 2.0/(N+1.0)*(v(i) - w(i-1));
        }
        else 
            // For first value take the 10 day average
            ublas::vector_range<ublas::vector<double> > 
                       vr(v,ublas::range(0, 10));
            w(i) = sum(vr)/vr.size();
    }
}


