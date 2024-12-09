#ifndef LinkedList_H
#define LinkedList_H

#include <string>
#include "Node.h"

class Node;

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;
    std::string speciesName;

public:
    LinkedList(const std::string& speciesName);
    LinkedList();
    ~LinkedList();
    Node* getHead() const;
    Node* getTail() const;
    void setHead(Node* toSet);
    void setTail(Node* toSet);
    int getSize();
    void addAnimal(Animal* animal);
    void removeAnimal(Animal* animal);
};

#endif