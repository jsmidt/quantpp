#include <iostream>
#include <cstring>
#include "stock.hpp"

using std::cout;
using std::endl;
using std::strcpy;

Stock::Stock(char *n, size_t m) : open(m), close(m), high(m), low(m)
{
   strcpy(name, n);
   open(0) = 5.0;
   close(0) = 2.0;
   high(0) = 4.0;
   low(0) = 6.0;
}

Stock::~Stock()
{
   cout << "Object '" << name << "' has been destroyed" << endl;
}

size_t Stock::size()
{
    return open.size();
}
