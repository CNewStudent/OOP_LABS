// OOP_L2_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "RemoveSpace.h"
#include <iostream>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	string strLine, newStr;
	cout << "input string: ";
	getline(cin, strLine);
	newStr = RemoveExtraSpaces(strLine);
	cout << newStr << endl;
	return 0;
}

