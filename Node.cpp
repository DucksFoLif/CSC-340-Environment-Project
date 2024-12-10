#include "Node.h"

using namespace std;

Node::Node(Animal* data){
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}
Node::Node(){
   this->data = new Animal();
   this->next = nullptr;
   this->prev = nullptr;
}

Node::~Node() {}

Animal* Node::getData() const {
    return data;
}

void Node::setData(Animal* data) {
    data = data;
}

Node* Node::getNext() const {
    return next;
}

void Node::setNext(Node* nextNode) {
    next = nextNode;
}

Node* Node::getPrev() const {
    return prev;
}

void Node::setPrev(Node* prevNode) {
    prev = prevNode;
}