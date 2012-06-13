#ifndef __STOCK_HPP_
#define __STOCK_HPP_

#include <boost/numeric/ublas/vector.hpp>
#include <string>
using namespace boost::numeric::ublas;
using std::string;

class Stock
{
private:
    std::string name;

public:
    Stock(std::string n, size_t m);
    size_t size();
    const std::string get_name() { return name; }
    std::vector<std::string> date;
    vector<double> open;
    vector<double> high;
    vector<double> low;
    vector<double> close;
    vector<double> volume;
    void load_stock_csv(std::string filename);
    ~Stock();
};

#endif /* __STOCK_HPP_ */

