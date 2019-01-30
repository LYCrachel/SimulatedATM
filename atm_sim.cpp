#include <iostream>
#include "ATM.h"
using namespace std;


int getSimParameters(int &M, int &N, int &C, int *&atime_list, int *&ttime_list);
void displaySimResults(int wait, int C);
bool ifEmpty(int s); 
int findQtoInsert(int numATM,ATM* arr,int csize);

int minuteOfSim,numOfATM,numOfCus;
int *atimeArr, *ttimeArr;

int currentTime ;
int cusArrived ;
int cusFinished;
int shortestQ;
int currentCusIndex;
int cusSize;




int main () {

  int minuteOfSim,numOfATM,numOfCus;
  int *atimeArr, *ttimeArr;
  int total_wait_time = 0;
  int param_err = getSimParameters(minuteOfSim, numOfATM, numOfCus, atimeArr, ttimeArr);
  if (param_err) {
    cerr << "Error in simulation parameters." << endl;
    return -1;
  }



currentTime = 0;
cusArrived = 0;
cusFinished = 0;
ATM* atmArr = new ATM[numOfATM];


// MAIN LOOP
while (currentTime < minuteOfSim || cusArrived < numOfCus || cusFinished < cusArrived) {
	
	cout << "time " << currentTime << " starts"<<endl; // for tracking every moment

	cusSize = 0; // becomes 0 with every loop starts
	for (int k = currentCusIndex; k < numOfCus; k++){   // find index and number of customers at the moment
		if (atimeArr[k] == currentTime) {
			currentCusIndex = k;
			cusSize++;
		}
	}
	currentCusIndex = currentCusIndex - cusSize + 1; 


	bool isEmpty = ifEmpty(cusSize);
	
	if (currentTime < minuteOfSim && !isEmpty) {   // if there still new customer coming
		for (int i =0;i < numOfCus; i++){  // find a ATM or atmQ to insert EACH customer
			shortestQ = findQtoInsert(numOfATM,atmArr,cusSize);
			Customer c(atimeArr[currentCusIndex], ttimeArr[currentCusIndex]);  //creat a customer object to be insert to an ATM object 	
			atmArr[shortestQ].insertCus(c); 
			cout << "IN Main: just insert or enqueue a Cus N0. " << currentCusIndex << "to shorstest ATM Q num"<< shortestQ<< endl;
			cusArrived++;
			currentCusIndex++;
		}
	}
	
			

	// process Each ATM and return 1.each customer's wait time 2.if there is customer processed/left
	for (int i = 0 ; i <numOfATM ; i++){
		total_wait_time += atmArr[i].processCus(currentTime);
		cusFinished += atmArr[i].getCusProcessed();
	}

	cout << "time " << currentTime << " is over,total wait time is" << total_wait_time << endl; // tracking current time
	cout << endl;
	currentTime ++;
}



  delete[] atmArr; // delete new

  // Display statistics on the simulation.
  displaySimResults(total_wait_time, numOfCus);


  // Return total_wait_time, will be used by test script.
  return total_wait_time;
}




// Read the simulation parameters from standard input (cin).
// Parameters:
// M: minutes to run simulation
// N: number of ATMs
// C: number of customers
// atime_list: array of customer arrival times
// ttime_list: array of customer transaction times
//    customer i arrives at time atime_list[i] and performs a transaction that takes ttime_list[i] minutes
//
// All parameters are pass-by-reference (note & character).  This means assignments in this function will affect value from calling function
// 
// Return value:
// returns 0 if successful read of input
// non-zero values used to denote failure
//   1: simulation time < 1
//   2: number of ATMs < 1
//   3: number of customers < 1
//   4: a customer's transaction time < 1
//   5: customer list is not sorted by arrival time
//   6: customer arrival time later than simulation end time
int getSimParameters(int &M, int &N, int &C, int *&atime_list, int *&ttime_list) {
  // Code to read simulation parameters.
  cout << "Run an ATM simulation" << endl;

  cout << "Enter the number of minutes" << endl;
  cin >> M;
  // Check input validity.
  if (M < 1) {
    cerr << "Simulation for invalid length of time." << endl;
    return 1;
  }

  
  cout << "Enter the number of ATMs" << endl;
  cin >> N;
  // Check input validity.
  if (N < 1) {
    cerr << "Simulation for invalid number of ATMs." << endl;
    return 2;
  }


  // Read customer list
  cout << "Enter the number of customers" << endl;
  cin >> C;
  if (C < 1) {
    cerr << "Simulation for invalid number of customers." << endl;
    return 3;
  }
  // Allocate memory for customer list.
  atime_list = new int [C];
  ttime_list = new int [C];

  // Read C customers
  int atime = -1;
  int prevatime = -1;
  int ttime = 0;
  for (int i=0; i<C; i++) {
    cout << "Enter customer arrival and transaction time." << endl;
    cin >> atime;
    cin >> ttime;

    // Check input validity.
    if (ttime < 1) {
      cerr << "Invalid transaction time." << endl;
      return 4;
    }
    if (atime < prevatime) {
      cerr << "Arrival times not sorted." << endl;
      return 5;
    }
    if (atime >= M) {
      cerr << "Arrival time later than simulation end time." << endl;
      return 6;
    }
    prevatime = atime;

    atime_list[i] = atime;
    ttime_list[i] = ttime;
  }

  // All went well, return 0.
  return 0;
}


// Display statistics on the simulation.
// wait: Total wait time of all customers in simulation.
// C: total number of customers in simulation.
void displaySimResults(int wait, int C) {
  cout << "Simulation results" << endl;
  cout << "Number of customers: " << C << endl;
  cout << "Total wait time: " << wait << endl;
  cout << "Average wait time: " << ((double) wait)/((double) C) << endl;
}

bool ifEmpty(int s){
	int size = s; 
	if (size == 0){return true;}
	else {return false;}
}


int findQtoInsert(int numATM,ATM* arr,int csize){
		int s;
		for (int i = 0; i < csize; i++) {
			for (int m = 0; m < numATM; m++) {
				s = -1;
				if (arr[m].returnAvail()) {
					s = m;
					return s;
				}
			}

			if (s == -1) {
					s = 0;
					for (int k = 0; k < (numATM - 1); k++) {
						int sizeQ = arr[k].qSize();
						if (sizeQ > arr[k + 1].qSize()) {
							s = k + 1;

						}
					}
			return s;
			}
		}
	
}


