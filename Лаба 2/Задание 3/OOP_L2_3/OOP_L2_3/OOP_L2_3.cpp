// OOP_L2_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Functions_L2_3.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	string strLine;
	map<string, int> dictionary;

	cout << "input text: ";
	getline(cin, strLine);
	dictionary = FillInDictionary(strLine);
	
	
	PrintResult(dictionary);
	

	getchar();

	return 0;
}

