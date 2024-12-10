#include "Population.h"
#include <iostream>
using namespace std;

Population::Population(){
    head = nullptr;
    tail = nullptr;
    size = 0;
    speciesName = "defaultSpecies";
}

Population::Population(const std::string& speciesName){
    //read in csv
    //make animals equivalent to value
}

Population::~Population(){
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->getNext();
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr;
}

Node* Population::getHead() const{
    return head;
}
Node* Population::getTail() const{
    return tail;
}
void Population::setHead(Node* toSet){
    this->head = toSet;
}
void Population::setTail(Node* toSet){
    this->tail = toSet;
}

int Population::getSize(){
    return size;
}

void addAnimal(Animal* animal){
    //
}

void removeAnimal(Animal* animal){

}