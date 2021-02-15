#include <iostream>

using namespace std;

//Pass const as a reference
void CreateArrayOfSize(const int&);

//Pass const as a pointer
void CreateArrayWithPointer(const int*);

int lmain() {

    //Set const int reference to iSize
    const int& iSize = 5;

    CreateArrayOfSize(iSize);

    //Set standard int to 5
    int iSize2 = 5;
    //Copy standard int to pointer (Must initialize with the referenced variable since you are copying the memory location, and not the value
    const int* iSize3 = &iSize2;

    //Using the pointer variable name returns the pointer location in pointer as opposed to the memory location
    cout << endl << "iSize 3 as pointer " << iSize3;
    //We must use the * to tell the compiler we want the value held in that memory location since a point holds a memory location
    cout << endl << "iSize 3 is :" << *iSize3;

    //Pass memory location to function
    CreateArrayWithPointer(iSize3);

}

void CreateArrayOfSize(const int& iSize) {

    int iArray[iSize];
    cout << "iSize is :" << iSize;
    cout << endl << "iSize Location :" << &iSize;

}

void CreateArrayWithPointer(const int* iSize) {
    int iArray[*iSize];
    cout << endl << "iSize is :" << *iSize;
    cout << endl << "iSize Pointer is :" << &iSize;
}
