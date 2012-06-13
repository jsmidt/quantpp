/**********************************************************************
 **
 ** main.cpp - Main routine for Quant++.
 **
 ** Vesion history
 **     v0.1 - Joseph Smidt.  Initial upload 
 **
 *********************************************************************/

// Include Standard Template libraries routines. 
#include "stock.hpp"
using std::cout;
using std::endl;
using std::cerr;

int main (int argc, char** argv) {

    // Create stock.
    Stock s("Test",10);

    // Print stuff to make sure initalized correctly.
    std::cout << "Stock '" << s.get_name() << "' has " << s.size()
              << " elements " << s.open(0) << " " << s.close(0) << " " 
              << s.high(0) << " " << s.low(0) <<  std::endl;
    
    // Make sure proper filename was given.
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <csv file>" << endl;
        return -1;
    }

    // Load in values from CSV file from Yahoo Finance.
    s.load_stock_csv(argv[1]);

    // Print out loaded values.
    cout << "\nThis is what was loaded in:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << s.open(i) << " " << s.close(i) << " " << s.high(i) << " "
             << s.low(i)  << " " << s.volume(i) << endl;
    }

   return 0;
}

