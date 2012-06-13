#ifndef __STOCK_HPP_
#define __STOCK_HPP_

#include <boost/numeric/ublas/vector.hpp>
#include <string>
using namespace boost::numeric;

class Stock {
private:
    std::string name;

public:
    Stock(std::string n, size_t m);
    size_t size();
    const std::string get_name() { return name; }
    std::vector<std::string> date;
    ublas::vector<double> open;
    ublas::vector<double> high;
    ublas::vector<double> low;
    ublas::vector<double> close;
    ublas::vector<double> volume;
    void load_stock_csv(std::string filename);
    ~Stock();
};

#endif /* __STOCK_HPP_ */

