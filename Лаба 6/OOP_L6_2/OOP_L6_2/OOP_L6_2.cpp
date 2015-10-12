// OOP_L6_2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "CStudent.h"
//#include "/�����/2 ���� 2 �������/OOP/���� 6/OOP_L6_2/TheApplicationTests/STakhirException.h"
#include <iostream>
#include "CTakhirException.h"


int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		CStudent student("na me", "surname", "", 30);
		cout << student.GetName() << endl;
		cout << student.GetSurname() << endl;
		cout << student.GetPatronymic() << endl;
		cout << student.GetAge() << endl;
	}
	catch (CTakhirException const & e)
	{
		cout << "Error: " << e.what() << endl;
	}
	catch (exception const & e)
	{
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}

