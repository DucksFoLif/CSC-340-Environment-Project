#ifndef POPULATION_H
#define POPULATION_H

#include <string>
#include "Node.h"

class Population {
private:
    Node* head;
    Node* tail;
    int size;
    std::string speciesName;

public:
    Population(const std::string& speciesName);
    Population();
    ~Population();
    Node* getHead() const;
    Node* getTail() const;
    void setHead(Node* toSet);
    void setTail(Node* toSet);
    int getSize();
    void addAnimal(Animal* animal);
    void removeAnimal(Animal* animal);
};

#endif