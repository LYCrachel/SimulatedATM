/*
 * Customer.cpp
 *
 */

#include "Customer.h"

Customer::Customer(){
atime = 0;
ttime = 0;
}

Customer::Customer(int a , int t){
atime = a;
ttime = t;
}

Customer::Customer(const Customer& cus) {
	atime = cus.getAtime();
	ttime = cus.getTtime();
}

int Customer::getAtime() const{
return atime;
}

int Customer::getTtime() const{
return ttime;
}

void Customer::setAtime(int a){
atime = a;
}

void Customer::setTtime(int t){
ttime = t;
}

// TO DO:: Fill in.


