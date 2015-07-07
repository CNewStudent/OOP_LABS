// OOP_L7_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "FindMax.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

struct SportsmenInfo
{
	string name;
	double height, weight;
};

bool FindMaxHeight(SportsmenInfo const &firstParametr, SportsmenInfo const &secondParametr)
{
	return firstParametr.height > secondParametr.height;
}

bool FindMaxWeight(SportsmenInfo const &firstParametr, SportsmenInfo const &secondParametr)
{
	return firstParametr.weight > secondParametr.weight;
}

void PrintInfo(SportsmenInfo & sportsmens)
{
	cout << "Name: " << sportsmens.name << endl;
	cout << "Height: " <<sportsmens.height << endl;
	cout << "Weight: " <<sportsmens.weight << endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<SportsmenInfo> Sportsmens = {
			{ "Bob", 190, 80 },
			{ "Jonh", 194.5, 89 },
			{ "Piter", 199, 85 }
	};

	SportsmenInfo maxValue;

	if (FindMax(Sportsmens, maxValue, FindMaxHeight))
		PrintInfo(maxValue);

	cout << endl;

	if (FindMax(Sportsmens, maxValue, FindMaxWeight))
		PrintInfo(maxValue);
	return 0;
}

