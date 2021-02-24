
#ifndef MENUMAKER_H
#define MENUMAKER_H
#include <string>
#include <iostream>
using namespace std;


class MenuMaker
{

public:
	void menuStart(int menuNum, int crtlNum);
	void makeMenu(const string menu, int omitNumber, string numReplacment);
	void menuFormatter(int, string, int omitMumber, string numReplacement);
	int optionsNum();

};
#endif