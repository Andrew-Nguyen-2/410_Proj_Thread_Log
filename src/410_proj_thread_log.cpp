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

//TODO linker errors?  Did you include the pthread library?   And set the proper dialect?
//TODO declare globals

/***
 * 
 * TODO log info to both file and console (you can do this with 2 Logger objects)
 * TODO this function should run until main (or another thread) asks it to quit
 * @param info  to log
 * returns void
 */
void fun(string info){

}
int main() {
	
	//TODO start as many threads as you have cores (see std::thread::hardware_concurrency())
	//TODO save these threads in a vector

	//TODO let threads run a bit (5 seconds)
	this_thread::sleep_for(chrono::milliseconds(5000));
	
	//TODO ask them all to stop
	
	//TODO wait for all threads to finish
	
	return 0;
}