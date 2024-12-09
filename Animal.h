#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
protected:
    std::string EPstr;
    int EPlevel;
    int hungerReq;
    std::string state;

    //can be removed if we don't like it
    unsigned short int* stats; // H,G,S
    

public:
    Animal();
    ~Animal();


};




#endif // ANIMAL_H