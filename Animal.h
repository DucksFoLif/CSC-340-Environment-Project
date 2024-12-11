#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
protected:
    //given from uml
    std::string EPstr;
    int EPlevel;
    int hungerReq;
    std::string state;
    // bool sex;
    

    //can be removed if we don't like it
    double hunger; // inverse of fullness starts at 0
    double fullness; //starts at 100
    unsigned short int* stats; // Stealth/Evasion, Eating, Intelligence, Appeal (Mating stat)
    

public:
    Animal();
    Animal(const int *given_stats);
    virtual ~Animal();

    

    //get base stats
    int getStealthSkill();
    int getEatSkill();
    int getIntelligence();

    //set base stats
    

    //get hunger stats
    double getHunger();
    double getFullness();

    //set hunger stats
    void setHunger(double newHunger);
    void setFullness(double newFullness);

    //reproduction
    Animal* reproduce();

    
};




#endif // ANIMAL_H