#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
    speciesName = "defaultSpecies";
}

LinkedList::LinkedList(const std::string& speciesName){
    //read in csv
    //make animals equivalent to value
}

LinkedList::~LinkedList(){
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->getNext();
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr;
}

Node* LinkedList::getHead() const{
    return head;
}
Node* LinkedList::getTail() const{
    return tail;
}
void LinkedList::setHead(Node* toSet){
    this->head = toSet;
}
void LinkedList::setTail(Node* toSet){
    this->tail = toSet;
}

int LinkedList::getSize(){
    return size;
}

void LinkedList::addAnimal(Animal* animal){
    Node* temp = head;
    while(temp){
        //if animal eating stat <= temp eating stat
            //add it into the array
            return;
    }
    temp = temp->getNext();
}

void LinkedList::removeAnimal(Animal* animal){
    Node* temp = head;
    while(temp){
        if(animal == temp->getData()){
            temp->getNext()->setPrev(temp->getPrev());
            temp->getPrev()->setNext(temp->getNext());
            delete temp;
            return;
        }
        temp = temp->getNext();
    }
    
}