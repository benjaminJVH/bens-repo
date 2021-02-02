/*
 * Assignment_1_Class.cpp
 *
 *  Created on: Jan 24, 2021
 *      Author: Dustin Brown
 *
 *      Class definition cpp file
 */

#include "WordArray.h"
#include <array>
#include <string>
#include<iostream>
using namespace std;

string arrWord[12];



void WordArray::toWordArray(string input, int wordCount) {
	int arrayNum;
	arrayNum = (wordCount - 1);
	arrWord[arrayNum] = input;	
	cout << arrWord[arrayNum] << " " << endl;
}

string WordArray::viewArray(int wordCount) {
	return 0;
}



void WordArray::delArrayElements(int userChoice) {

}