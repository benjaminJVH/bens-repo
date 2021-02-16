
#ifndef INPUTCHECK_H
#define INPUTCHECK_H
#include <string>
using namespace std;

class InputCheck {

public:
	//bool intInputCheck(bool& ignorZero, int choice, int* numOptions, bool& intLoop);

	bool intInputCheck(bool& intLoop, int userInput, const int* numOptions);

	//bool stringInputCheck(string& input, int* numOptions, bool& stringLoop);


};

#endif

