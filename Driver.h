#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include "Environment.h"

using namespace std;

class Driver
{
  //string 2ints 2 doubles

  public:
    static void initiateMenu(Environment* Enviro);
    static void parseMenuInput(Environment* Enviro, int inp);
  
};




#endif // DRIVER_H