// OOP_L7_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CMyArray.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CMyArray<double> doubleArray;
	doubleArray.Add(2.33);
	doubleArray.Add(3.32);
	doubleArray.Add(3.23);

	for (size_t i = 0; i < doubleArray.Size(); i++)
	{
		cout << doubleArray[i] << endl;
	}



	return 0;
}

