/*
 * Node.cpp
 *
 */

#include "Node.h"

Node::Node():next(NULL),c(0,0){
}

Node::Node(Customer newCustomer){
  setCus(newCustomer);
  next = 0;
}

void Node::setCus(Customer newCustomer) {
c = newCustomer;
}


int Node::getCusAtime() const{
	return c.getAtime();
}
	
int Node::getCusTtime() const{
	return c.getTtime();
}

Customer& Node::getCus() {
	return c;
}

void Node::setNext(Node* tempnode) {
	next = tempnode;
}

Node* Node::getNext() {
	return next;
}

