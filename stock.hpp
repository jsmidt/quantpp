#ifndef __STOCK_HPP_
#define __STOCK_HPP_

#include <boost/numeric/ublas/vector.hpp>

using namespace boost::numeric::ublas;

class Stock
{
private:
    char name[50];

public:
    Stock(char *n, size_t m);
    size_t size();
    const char* get_name() { return name; }
    vector<double> open;
    vector<double> high;
    vector<double> low;
    vector<double> close;
    ~Stock();
};

#endif /* __STOCK_HPP_ */

