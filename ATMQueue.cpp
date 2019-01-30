/*
 * ATMQueue.cpp
 *
 */

#include "ATMQueue.h"
#include <iostream>

ATMQueue::ATMQueue(){
	size= 0;
	front = NULL;
	back = NULL;
 }

ATMQueue::~ATMQueue(){
	while (size != 0){ ATMQueue::dequeue(); }
}

Node* ATMQueue::getFront() { return front; }

int ATMQueue::getSize() const { return size; }

bool ATMQueue::ifEmpty(){
	if (size==0)	return true;
	else 		return false;
}

void ATMQueue::enqueue(Customer newCus){
	Node* temp = new Node(); //remember to delete
	temp->setCus(newCus);
	std::cout << "About to enqueue customer with A T time " << temp->getCusAtime() << temp->getCusTtime() << std::endl;
	if (size==0){
		front = temp;
		back = temp;
	}
	else{
		back->setNext(temp);
		back = temp;
	}
	std::cout << "The queue now has front Ttime: " << front->getCusTtime() << " and back Ttime :" << back->getCusTtime() << std::endl;
	size++;
}

void ATMQueue::dequeue(){
	if (size==0){
		 return;
	}
	else{
		Node* temp = front;
		front = front->getNext();
		delete temp;  //deleted
		temp = new Node();
		size--;
	}
}

	
int ATMQueue::getFrontAtime(Node* node) const { return node->getCusAtime(); }


int ATMQueue::getFrontTtime(Node* node)const { 	return node->getCusTtime(); }
