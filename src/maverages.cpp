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




