/*
 * ATMQueue.h
 *
 */

#ifndef ATMQUEUE_H_
#define ATMQUEUE_H_

#include "Customer.h"
#include "Node.h"

class ATMQueue {

public:
	ATMQueue();
	~ATMQueue();
	Node* getFront();
	int getSize() const;
	bool ifEmpty();
	void enqueue(Customer);
	void dequeue();	
	int getFrontAtime(Node*)const;
	int getFrontTtime(Node*)const;

private:
	int size;
	Node* front;
	Node* back;
	
};

#endif /* ATMQUEUE_H_ */
