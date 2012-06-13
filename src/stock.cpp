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
using std::cerr;
using std::fstream;
using std::ios;

Stock::Stock(std::string n, size_t m) : 
    open(m), close(m), high(m), low(m), volume(m) 
{
   name = n;
}

void Stock::load_stock_csv(std::string filename) 
{
    std::vector< std::vector<double> > csv_values;
    fstream file(filename.c_str(), ios::in);

    // Load in values.
    if (file) {
        typedef boost::tokenizer< boost::char_separator<char> > Tokenizer;
        boost::char_separator<char> sep(",");
        std::string line;

        // Skip one line for header.
        getline(file, line);

        while (getline(file, line)) {
            Tokenizer info(line, sep);   // tokenize the line of data
            std::vector<double> values;

            for (Tokenizer::iterator it = info.begin(); it != info.end(); ++it){
                if (it == info.begin()) 
                    this->date.push_back(*it);
                else
                    values.push_back(strtod(it->c_str(), 0));
            }

            // store array of values
            csv_values.push_back(values);
        }
    }
    else {
        cerr << "Error: Unable to open file " << filename << endl;
    }

    // display results
    cout.precision(2);
    cout.setf(ios::fixed,ios::floatfield);

    // Load values into stock arrays. 
    for (size_t i = 0; i < csv_values.size(); i++) {
        this->open(i)   = csv_values[i].at(0);
        this->high(i)    = csv_values[i].at(1);
        this->low(i)   = csv_values[i].at(2);
        this->close(i)  = csv_values[i].at(3);
        this->volume(i) = csv_values[i].at(4);
    }
}

Stock::~Stock() 
{
    // Destructor
}

size_t Stock::size() {
    return open.size();
}
