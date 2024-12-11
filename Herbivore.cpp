#include <iostream>
#include <string>
#include "Environment.h"
#include "Animal.h"
#include "Herbivore.h"

using namespace std;

const int MAX_STAT_SIZE = 4 ;
const int RANDOM_RANGE = 100;


Herbivore::Herbivore() : Animal() 
{}

Herbivore::Herbivore(int *given_stats) : Animal(given_stats)
{

    
}



Herbivore::~Herbivore() 
{}

double Herbivore::eat(double foodLeft)
{
    //values allocated so I don't have to repeat function calls
    double current_fullness = this -> getFullness();
    double current_hunger = this -> getHunger();

    //calculate luck
    int randomMult = 1 + (rand() % RANDOM_RANGE); 

    //calculate how much food the animal attempts to eat
    double animalWant = current_hunger * (5.0 / randomMult) * ((this -> getEatSkill() + 1) / 256.0);

    //calculate potential hunger and fullness values
    //double potential_fullness = this -> getFullness() + animalWant;
    //double potential_hunger = this ->getHunger() - animalWant;

    // change value and finish eating
    if(animalWant < foodLeft)// if there is enough food for the animal to eat and have some left over
    {
     if((current_fullness + animalWant) >= 100) //the animal would be too full or full
     {
        //calculate food left after eating 
        foodLeft -= (animalWant + current_fullness - 100.0);

        //apply hunger changes
        this -> setFullness(100.0);
        this ->setHunger(0.0);
    }
    else // if the animal won't be full enough but there is food left over
    {
        //calculate food left after eating
        foodLeft -= animalWant;

        //apply hunger changes
        this -> setFullness(current_fullness + animalWant);
        this -> setHunger(current_hunger - animalWant);
    }
   }
   else //there isn't enough food left for the animal to eat to get waht they want, but they still could get full
   {
    if((current_fullness + foodLeft) >= 100) //animal would be full from eating what is left 
    {
        //calculate food left after eating
        foodLeft = (foodLeft + current_fullness - 100.0);

        //apply hunger changes
        this -> setFullness(100.0);
        this ->setHunger(0.0);
    }
    else //if the animal wouldn't be full from eating whats left and there isn't enough food
    {
        //apply hunger changes
        this -> setFullness(current_fullness + foodLeft);
        this -> setHunger(current_hunger - foodLeft);

        //no food left
        foodLeft = 0;

    }
   }
   //return changes to environment
    return foodLeft;
}

