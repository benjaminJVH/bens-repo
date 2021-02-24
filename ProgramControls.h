#ifndef PROGRAMCONTROLS_H
#define PROGRAMCONTROLS_H
#include <string>
using namespace std;

class ProgramControls
{

public:

	void startPCProgram(int menuNum, int optionOmit);
	string menuDescr(int menuNum);
	string errorMessages(int errNum);
	int omitNumber(int intOmit);
	//int startingIntOption(int optionStart);
	string replaceOmitNum();
	int MaxChar(int MAX_CHAR_LIMIT);
	bool loops(int loopNum);
	string iconSelector(int iconSelect);
};

#endif