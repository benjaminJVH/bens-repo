
#ifndef INPUTCHECK_H
#define INPUTCHECK_H
#include <string>
using namespace std;

class InputCheck {

public:	

	bool intInputCheck(bool& intLoop, int& intUserInput, int numOptions, string intErrorMessage_1);	
	bool strIgnoreError(bool& rtnIntLoop, int& intUserInput, bool& skipOptionItr);
	bool stringInputCheck(string& strUserInput, int numOptions, bool& stringLoop, const int* MAX_CHAR_LIMIT, 
		const string strErrorMessage_1);


};

#endif

