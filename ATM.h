/*
 * ATM.h
 *
 */


#ifndef ATM_H_
#define ATM_H_

#include "Customer.h"
#include "Node.h"
#include "ATMQueue.h"

class ATM {

public:
	ATM();
	~ATM(); //destructor;
	void insertCus(Customer);
	int processCus(int curTime);
	int qSize() const;
	int getTranTime() const;
	bool returnAvail();
	int getCusProcessed()const;


private:
	int tranTime;
	int waitTime;
	ATMQueue* atmQ;
	bool available;
	int cusProcessed; // return 0 or 1 depending on if after this time there's customer left 
	

};

#endif /* ATM_H_ */
