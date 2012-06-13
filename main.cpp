#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "stock.hpp"
using std::cout;
using std::endl;

int main () {
    using namespace boost::numeric::ublas;
    vector<double> v (3);

    for (unsigned i = 0; i < v.size (); ++ i)
        v (i) = i;
    std::cout << v << std::endl;

    Stock s("Test",10);
    std::cout << "Stock '" << s.get_name() << "' has " << s.size()
                << " elements " << s.open(0) << " " << s.close(0) << " " << s.high(0) << " " << s.low(0) <<  std::endl;

    //for (int i = 0; i < 6; i++) {
    //    cout << s.close(i) << endl;
    //}

    s.load_stock_csv("table.txt");

    //for (int i = 0; i < 6; i++) {
    //    cout << s.close(i) << endl;
    //}

   return 0;
}

