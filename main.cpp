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
#include <fstream>
using std::cout;
using std::endl;
using std::cerr;
using std::fstream;
using std::ios;

int main (int argc, char** argv) {
 
    // Make sure proper filename was given.
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <csv file>" << endl;
        return -1;
    }

    string filename, line;
    filename = argv[1];

    // Count lines in file.
    size_t count = 0;
    fstream file(filename.c_str(),ios::in); while (getline(file, line)) count++;

    // Create stock.
    Stock s("Test",count-1);

    // Load in values from CSV file from Yahoo Finance.
    s.load_stock_csv(filename);

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

