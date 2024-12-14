#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(){
    this -> head = nullptr;
    this -> tail = nullptr;
    this -> size = 0;
    this -> speciesName = "defaultSpecies";
}

LinkedList::LinkedList(const std::string& speciesName){
    //read in csv
    //make animals equivalent to value
    this->speciesName = speciesName;
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
    return this -> head;
}
Node* LinkedList::getTail() const{
    return this -> tail;
}
void LinkedList::setHead(Node* toSet){
    this->head = toSet;
}
void LinkedList::setTail(Node* toSet){
    this->tail = toSet;
}

int LinkedList::getSize(){
    return this -> size;
}

string LinkedList::getSpeciesName() const{
    return speciesName;
}

void LinkedList::addAnimal(Animal* animal) {
    Node* temp = head;
    Node* newNode = new Node(animal);

    while (temp) {
        if (animal->getEatSkill() <= temp->getData()->getEatSkill()) {
            if (temp == head) {
                newNode->setNext(head);
                head->setPrev(newNode);
                head = newNode;
            } else {
                Node* prevNode = temp->getPrev();
                newNode->setNext(temp);
                newNode->setPrev(prevNode);
                if (prevNode) prevNode->setNext(newNode);
                temp->setPrev(newNode);
            }
            (this -> size)++;
            return;  // Stop after inserting
        }
        temp = temp->getNext();
    }

    // Append at the end if no suitable position was found
    if (!temp) {
        if (!head) {
            // If the list is empty
            head = newNode;
        } else {
            Node* tail = head;
            while (tail->getNext()) {
                tail = tail->getNext();
            }
            tail->setNext(newNode);
            newNode->setPrev(tail);
        }
        (this -> size)++;
    }
    
}




void LinkedList::removeAnimal(Animal* animal) {
    Node* temp = head;

    while (temp) {
        if (animal == temp->getData()) {
            if (temp == head) {
                head = temp->getNext();
                if (head) head->setPrev(nullptr);
            } else if (temp == tail) {
                tail = temp->getPrev();
                if (tail) tail->setNext(nullptr);
            } else {
                temp->getNext()->setPrev(temp->getPrev());
                temp->getPrev()->setNext(temp->getNext());
            }

            delete temp;
            size--;
            return;
        }
        temp = temp->getNext();
    }
}

/* //OLD CODE REVERT IF NECCESSARY
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
*/