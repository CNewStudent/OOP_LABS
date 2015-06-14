// OOP_L6_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CStudent.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{

	try
	{
		CStudent student("name", "surname", "", 30);
		cout << student.GetName() << endl;
		cout << student.GetSurname() << endl;
		cout << student.GetPatronymic() << endl;
		cout << student.GetAge() << endl;
	}
	catch (logic_error const & e)
	{
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}

