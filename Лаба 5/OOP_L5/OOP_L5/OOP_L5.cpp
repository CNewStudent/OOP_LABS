// OOP_L5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CVector3D.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CVector3D vectorOne(10, 10, 5);
	CVector3D vectorTwo(9, 2, 6);

	//CVector3D vectorResultPlus = vectorOne += vectorTwo;
	

	
	cout << vectorOne.GetLength() << endl;
	cout << vectorTwo.GetLength() << endl;

	
	return 0;
}

