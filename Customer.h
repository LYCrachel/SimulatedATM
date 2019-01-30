/*
 * Customer.h
 *
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {
  	
public:
	Customer();
	Customer(int a, int t);
	Customer(const Customer& cus);
	int getAtime() const;
	int getTtime() const;
	void setAtime(int);
	void setTtime(int);

private:
	int atime;
	int ttime;

};

#endif /* CUSTOMER_H_ */
