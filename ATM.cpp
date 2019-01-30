/*
 * ATM.cpp
 *
 */

#include "ATM.h"
#include <iostream>

ATM::ATM(){
	tranTime = 0;
	waitTime = 0;
	available = true;
	atmQ = new ATMQueue();
	cusProcessed = 0;
}


ATM::~ATM() { delete atmQ; } //destructor

bool ATM::returnAvail() { return available; }  // return if this ATM is available ,for finding a atmq to insert cus

void ATM::insertCus(Customer c){
	if (available){
	tranTime = c.getTtime();
	available = false;
	std::cout << "Just insert a customer with ttime" << c.getTtime() << std::endl;
	}
	else {
	atmQ->enqueue(c);
	}
}



int ATM::processCus(int currentTime){ // process customer (if there is any) and change data member cusProcessed if after this moment there is a customer leaving ATM
	cusProcessed = 0;  // either 1 or 0
	std::cout << "Before processing, tranTime is: "<< tranTime << std::endl;
	if (tranTime != 0){
	tranTime = tranTime - 1;
		if (tranTime ==0) {
			cusProcessed = 1;
		available = true;
		}
	available = false;
	waitTime = 0;
	}
	else if (tranTime == 0 ) {
		if (atmQ->getFront() == NULL) {  // check if the queue is empty (no next customer)
			waitTime = 0;
			available = true;
		}
		else {
			tranTime = atmQ->getFrontTtime(atmQ->getFront()); // set trantime to next cus's ttime
			std::cout << "Just set tranTime and did not - 1, its" << tranTime << std::endl; // tracking the value just passed to trantime
			if (tranTime != 0) {
				tranTime = tranTime - 1;
				if (tranTime == 0) {  // after this moment, if the cus is gone
					cusProcessed = 1;  // only if cus left it becomes1
					available = true;
				}
				waitTime = (currentTime - atmQ->getFrontAtime(atmQ->getFront()));
				atmQ->dequeue();
				available = false;
			}
		}
	}
	std::cout << "after processing cus, this ATM has another trantime:" << tranTime <<std::endl;
	return waitTime;
}

int ATM::qSize() const { return atmQ->getSize(); } 

int ATM::getTranTime() const{ return tranTime; }

int ATM::getCusProcessed() const { return cusProcessed;}

