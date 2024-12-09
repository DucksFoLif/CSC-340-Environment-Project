#include <iostream>
#include <string>
#include "Environment.h"
#include "Animal.h"

using namespace std;

const int MAX_STAT_SIZE = 3;



Animal::Animal()
{
    this -> EPstr = "";
    this -> EPlevel = -1;
    this -> hungerReq = -1;
    this -> state = "";

    //new stuff for stats
    //declaring an array of 3
    this -> stats = new short unsigned int[MAX_STAT_SIZE];
    this -> stats[0] = 0;
    this -> stats[1] = 0;
    this -> stats[2] = 0;
}
Animal::~Animal()
{
    delete stats;
}
