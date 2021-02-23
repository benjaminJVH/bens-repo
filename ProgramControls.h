#ifndef PROGRAMCONTROLS_H
#define PROGRAMCONTROLS_H
#include <string>
using namespace std;

class ProgramControls
{

public:

	void startPCProgram();
	string menuDescr(int menuNum);
	string errorMessages(int errNum);
	int omitNumber(int intOmit);
	string replaceOmitNum();
	int MaxChar(int MAX_CHAR_LIMIT);
	bool loops(int loopNum);
};

#endif