//============================================================================
// Name        : 410_proj_thread_log.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <thread>
#include <iostream>
#include <vector>
#include "../includes/constants.h"
#include "../includes/Logger.h"

using namespace std;

//NOTE: you should have no mutexes in this file
//TODO linker errors?  Did you include the pthread library?   And set the proper dialect?
//TODO declare globals

Logger lg1(LOG_TYPE::LOG_FILE, FILENAME);
Logger lg2(LOG_TYPE::LOG_CONSOLE);
bool doWork = true;

/***
 * TODO log info to both file and console. You can do this with 2 Logger objects. 
 * 		Note:  These logger objects cannot be local variables, they must be shared 
 * 		amongst the threads. (why?)
 * TODO this function should run until main (or another thread) asks it to quit
 * @param info  to log
 * returns void
 */
void fun(string info){
	while (doWork){
		lg1.Log(info);
		lg2.Log(info);
	}
}

int main() {
	
	//TODO start as many threads as you have cores (see std::thread::hardware_concurrency())
	//TODO save these threads in a vector

	int numbThreads = thread::hardware_concurrency();
	vector<thread> threads;
	for (int i = 0; i < numbThreads/2; i++){
		if (i % 2 == 0){
			threads.push_back(thread(fun, "aaaaa"));
		}
		else{
			threads.push_back(thread(fun, "bbbbb"));
		}
	}

	//TODO let threads run a bit (5 seconds)
	this_thread::sleep_for(chrono::milliseconds(5000));
	
	//TODO ask them all to stop
	doWork = false;

	//TODO wait for all threads to finish
	
	for (auto& t : threads){
		t.join();
	}

	return 0;
}
