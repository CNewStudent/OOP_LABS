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

bool HeightIsLess(SportsmenInfo const &firstParametr, SportsmenInfo const &secondParametr)
{
	return firstParametr.height < secondParametr.height;
}

bool WeightIsLess(SportsmenInfo const &firstParametr, SportsmenInfo const &secondParametr)
{
	return firstParametr.weight < secondParametr.weight;
}

void PrintInfo(SportsmenInfo & sportsmens)
{
	cout << "Name: " << sportsmens.name << endl;
	cout << "Height: " <<sportsmens.height << endl;
	cout << "Weight: " <<sportsmens.weight << endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<SportsmenInfo> sportsmen = {
			{ "Bob", 190, 80 },
			{ "Jonh", 194.5, 89 },
			{ "Piter", 199, 85 }
	};

	SportsmenInfo maxValue;

	if (FindMax(sportsmen, maxValue, [](SportsmenInfo const &firstParametr, SportsmenInfo const &secondParametr)
	{return firstParametr.name < secondParametr.name; }))
		PrintInfo(maxValue);

	cout << endl;

	if (FindMax(sportsmen, maxValue, HeightIsLess))
		PrintInfo(maxValue);
	
	cout << endl;

	if (FindMax(sportsmen, maxValue, WeightIsLess))
		PrintInfo(maxValue);


	vector<int> numbers = {3, 2, 7, 3, 5, 0};
	int maxNumber;

	cout << endl;

	if (FindMax(numbers, maxNumber))
	{
		cout << maxNumber << endl;
	}

	//bool _16_is_less_than_7 = lessInt(16, 7); // 16 < 7

	return 0;
}

