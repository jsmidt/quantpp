/**********************************************************************
 **
 ** stock.cpp - Stock class.
 **
 ** Vesion history
 **     v0.1 - Joseph Smidt.  Initial upload 
 **
 *********************************************************************/


// Include Standard Template libraries routines.
#include <boost/tokenizer.hpp>
#include <iostream>
#include <cstring>
#include "stock.hpp"
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::strcpy;
using std::cerr;
using std::fstream;
using std::ios;

Stock::Stock(char *n, size_t m) : open(m), close(m), high(m), low(m), volume(m), other(m)
{
   strcpy(name, n);
   open(0) = 5.0;
   close(0) = 2.0;
   high(0) = 4.0;
   low(0) = 6.0;
}

void Stock::load_stock_csv(char* filename)
{
    std::vector< std::vector<double> > csv_values;
    fstream file(filename, ios::in);

    // Load in values.
    if (file) {
        cout << "\nLoading in values from csv file." << endl;
        typedef boost::tokenizer< boost::char_separator<char> > Tokenizer;
        boost::char_separator<char> sep(",");
        string line;

        while (getline(file, line)) {
            Tokenizer info(line, sep);   // tokenize the line of data
            std::vector<double> values;

            for (Tokenizer::iterator it = info.begin(); it != info.end(); ++it){
                // convert data into double value, and store
                // if(it == info.begin())
                //    cout << *it[0] << endl;
                values.push_back(strtod(it->c_str(), 0));
            }

            // store array of values
            csv_values.push_back(values);
        }
    }
    else {
        cerr << "Error: Unable to open file " << filename << endl;
        //return -1;
    }

    // display results
    cout.precision(2);
    cout.setf(ios::fixed,ios::floatfield);

    // Load values into stock arrays. 
    for (int i = 0; i < csv_values.size(); i++) {
        this->high(i)   = csv_values[i].at(0);
        this->low(i)    = csv_values[i].at(1);
        this->open(i)   = csv_values[i].at(2);
        this->close(i)  = csv_values[i].at(3);
        this->volume(i) = csv_values[i].at(4);
        this->other(i)  = csv_values[i].at(5);
    }
}

Stock::~Stock()
{
    // Destructor
}

size_t Stock::size()
{
    return open.size();
}
