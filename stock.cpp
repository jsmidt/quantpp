#include <iostream>
#include <cstring>
#include "stock.hpp"
#include <fstream>
using std::ifstream;

using std::cout;
using std::endl;
using std::strcpy;

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
    cout << filename << endl;
    ifstream in;
    in.open(filename);
    double a[6];

    for (int i = 0; i < 6; i++) {
        in >> this->open(i) >> this->close(i) >> this->high(i) >> 
            this->low(i) >> this->volume(i) >> this->other(i);
        cout << this->open(i) << " " <<  this->close(i) << " " << this->high(i) 
            << " " << this->low(i) << " " << this->volume(i) << " " <<
            this->other(i) << " "<< endl;
    }
}

Stock::~Stock()
{
   cout << "Object '" << name << "' has been destroyed" << endl;
}

size_t Stock::size()
{
    return open.size();
}
