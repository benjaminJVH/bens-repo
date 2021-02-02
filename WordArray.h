
//
//Assignment 2
//By Ben"jamin" V & Dustin "D-dawg" B
//Date: 02/01/2021




#ifndef WORDARRAY_H
#define WORDARRAY_H
#include <string>
using namespace std;

class WordArray
{
private:

	// Nothing today

public:

	// fun decs


	//read to array fun

	void toWordArray(string input, int wordCount);

	// view array contents fun

	string viewArray(int wordCount);

	// delete array elements

	void delArrayElements(int userChoice);

};
#endif // !WORDARRAY.H

