// OOP_L6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CTriangle.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

void IsDigit(string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			continue;
		}
		else
		{
			throw invalid_argument("invalid argument");
		}
	}

}

void PrintInfo(string str1, string str2, string str3)
{

	double side1, side2, side3;
	stringstream ss(str1);
	ss >> side1;
	stringstream ss2(str2);
	ss2 >> side2;
	stringstream ss3(str3);
	ss3 >> side3;
	CTriangle triangle(side1, side2, side3);

	cout << "side A: " << triangle.GetSide1() << endl;
	cout << "side B: " << triangle.GetSide2() << endl;
	cout << "side C: " << triangle.GetSide3() << endl;
	cout << "Perimetr: " << triangle.GetPerimeter() << endl;
	cout << "Area: " << triangle.GetArea() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string side1, side2, side3;
	while (!cin.eof())
	{
		try
		{	
			side1 = side2 = side3 = "";
			cout << "input A" << endl;
			cin >> side1;
			IsDigit(side1);
			cout << "input B" << endl;
			cin >> side2;
			IsDigit(side2);
			cout << "input C" << endl;
			cin >> side3;
			IsDigit(side3);
			PrintInfo(side1, side2, side3);
			cout << endl;
		}
		catch (std::logic_error const & e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		catch (...)
		{
		}
	}
	
	return 0;
}

