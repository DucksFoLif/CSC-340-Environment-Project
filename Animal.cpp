#include <iostream>
#include <string>
#include <ctime>

#include "Environment.h"
#include "Animal.h"

using namespace std;

const int MAX_STAT_SIZE = 4 ;


Animal::Animal()
{
    //given stats
    this -> EPstr = "";
    this -> EPlevel = -1;
    this -> hungerReq = -1;
    this -> state = "";
    // this -> sex = false;

    //new stuff for stats
    //declaring an array of MAX_STAT_SIZE
    this -> stats = new short unsigned int[MAX_STAT_SIZE];

    //this is unrolled for performance reasons, it would be a loop otherwise
    this -> stats[0] = 0;
    this -> stats[1] = 0;
    this -> stats[2] = 0;
    this -> stats[3] = 0;
}
Animal::Animal(const int *given_stats)
{
    //given stats
    this -> EPstr = "";
    this -> EPlevel = -1;
    this -> hungerReq = -1;
    this -> state = "";

    //declaring an array of MAX_STAT_SIZE
    this -> stats = new short unsigned int[MAX_STAT_SIZE];

    //first stat is the type of animal so skip it
    this -> stats[0] = given_stats[1];  // Stealth/Evasion
    this -> stats[1] = given_stats[2];  // Eating
    this -> stats[2] = given_stats[3];  // Intelligence
    this -> stats[3] = given_stats[4];  // Appeal

    //setting hunger stats
    hunger = 50; fullness = 50;

    /*
    //determining sex
    if (std::time(nullptr) % 2 == 0)
    {
        this -> sex = true;
    }

    else this -> sex = false;
    */

}
Animal::~Animal()
{
    delete[] stats;
}



int Animal::getEatSkill()
{return (this -> stats)[1];}


double Animal::getHunger()
{return this -> hunger;}
double Animal::getFullness()
{return this -> fullness;}


void Animal::setHunger(double newHunger)
{this -> hunger = newHunger;}
void Animal::setFullness(double newFullness)
{this -> fullness = newFullness;}
