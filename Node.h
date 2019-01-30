/*
 * Node.h
 *
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"
#include <cstdlib>


class Node {

public:
	Node();
	Node(Customer);
	void setCus(Customer);
	Customer& getCus();
	void setNext(Node*);
	Node* getNext();
	int getCusAtime() const;
	int getCusTtime() const;

private:
	Customer c;
	Node* next;

};

#endif /* NODE_H_ */
