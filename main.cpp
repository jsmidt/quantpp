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
    Stock s("Test",10043);

    // Make sure proper filename was given.
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <csv file>" << endl;
        return -1;
    }

    // Load in values from CSV file from Yahoo Finance.
    s.load_stock_csv(argv[1]);

    // Print out loaded values.
    cout << "\nThis is what was loaded in:" << endl;
    for (size_t i = 0; i < 20; i++) {
        cout << s.date.at(i) << " " << s.open(i) << " " << s.high(i) << " " 
             << s.low(i) << " " << s.close(i)  << " " << s.volume(i) << " "
             << s.adjclose(i) << endl;
    }
    cout << "Etc..." << endl;

   return 0;
}

