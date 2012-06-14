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
#include "maverages.hpp"
#include <fstream>
using std::cout;
using std::endl;
using std::cerr;
using std::fstream;
using std::ofstream;
using std::ios;

int main (int argc, char** argv) {
 
    // Make sure proper filename was given.
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <csv file>" << endl;
        return -1;
    }

    std::string filename, line;
    filename = argv[1];

    // Count lines in file.
    size_t count = 0;
    fstream file(filename.c_str(),ios::in); while (getline(file, line)) count++;

    // Create stock.
    Stock s("Test",count-1);

    // Load in values from CSV file from Yahoo Finance.
    s.load_stock_csv(filename);

    // Print out loaded values.
    ofstream out; out.open("output/output.txt");
    cout << "\nWrite output to file." << endl;
    for (size_t i = 0; i < s.date.size(); i++) {
        out << s.date.at(i) << " " << s.open(i) << " " << s.high(i) << " " 
             << s.low(i) << " " << s.close(i)  << " " << s.volume(i) << endl;
    }
    out.close();

    // Calculate moving averages and write to file.
    ublas::vector<double> w(s.close.size());
    size_t N = 50;
    sma(s.close,w,N);

    ublas::vector<double> ww(s.close.size());
    N = 200;
    sma(s.close,ww,N);

    ublas::vector<double> www(s.close.size());
    cma(s.close,www);

    out.open("output/sma.txt");
    cout << "\nWrite SMA to file." << endl;
    for (size_t i = 0; i < s.close.size(); i++)
    {
        out << w(i) << " " << ww(i) << " " << www(i) << " " << s.close(i) << endl;
    }

   return 0;
}

