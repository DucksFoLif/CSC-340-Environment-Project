#ifndef Node_H
#define Node_H

#include <string>
#include "Animal.h"
#include "Herbivore.h"

class Node {
private:
    Animal* data;
    Node* next;
    Node* prev;

public:
    Node(Animal* data);
    Node();
    ~Node();
    Animal* getData() const;
    void setData(Animal* newdata);
    Node* getNext() const;
    void setNext(Node* nextNode);
    Node* getPrev() const;
    void setPrev(Node* prevNode);
};

#endif