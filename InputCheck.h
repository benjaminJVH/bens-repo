
#ifndef INPUTCHECK_H
#define INPUTCHECK_H
#include <string>
using namespace std;

class InputCheck {

public:	

	bool intInputCheck(bool& intLoop, const bool ignoreOptionZero, int& intUserInput, const int* numOptions, string errorMessage_1);
	bool stringInputCheck(string& input, int* numOptions, bool& stringLoop);
	bool strIgnoreError(bool& rtnIntLoop, int& intUserInput, bool& skipOptionItr);


};

#endif

