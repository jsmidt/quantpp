/**
 ** maverages.hpp - moving averages
 **
 **     
 **
 **
 **********************************************************************/

#ifndef __MAVERAGES_HPP_
#define __MAVERAGES_HPP_

#include <boost/numeric/ublas/vector.hpp>
#include <string>
using namespace boost::numeric;

void sma(ublas::vector<double>, ublas::vector<double>&, size_t);
void cma(ublas::vector<double>, ublas::vector<double>&);
void ema(ublas::vector<double>, ublas::vector<double>&, float);


#endif /* __MAVERAGES_HPP_ */
