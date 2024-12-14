#ifndef HERBIVORE_H
#define HERBIVORE_H

#include <string>
#include "Animal.h"

class Herbivore : public Animal
{
private:


public:
    Herbivore();
    ~Herbivore();
    Herbivore(int *given_stats);

    double eat(double foodLeft) override ;



};




#endif // HERBIVORE_H