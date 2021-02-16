
#ifndef MENUMAKER_H
#define MENUMAKER_H
#include <string>
#include <iostream>
using namespace std;


class MenuMaker
{

public:
    void makeMenu(const bool ignoreZero, const string menuTitle, const char* charMenuOptions[], const int* numOptions);
};
#endif