// OOP_3_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Class.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


vector<int> fVectorWithData(string & sDigits)
{
	vector<int> vectorResult;
	string sDigit;


	sDigits += " ";

	for (unsigned int i = 0; i < sDigits.size(); i++)
	{
		int nChar = sDigits[i];
		if ((nChar >= '0' && nChar <= '9') || (nChar == ',') || (nChar == '-'))
		{
			sDigit += sDigits[i];
		}
		else
		{
			if (sDigit != "")
			{
				vectorResult.push_back(stoi(sDigit));
			}
			sDigit = "";
		}
	}

	return vectorResult;
}



int _tmain(int argc, _TCHAR* argv[])
{
	/*if (argc != 3)
	{
		cout << "check count arguments" << endl;
		return -1;
	}*/

	ifstream finFirstRectangle(argv[1]);
	ifstream finSecondRectangle(argv[2]);

	CRectangle CFirstRectangle(0, 0, 0, 0);
	CRectangle CSecondRectangle(0, 0, 0, 0);

	string sCommand;
	vector<int> vData;

	while (!finFirstRectangle.eof())
	{
		getline(finFirstRectangle, sCommand);
		if (strstr(sCommand.c_str(), "Rectangle"))
		{
			vData = fVectorWithData(sCommand);
			if (vData.size() != 4)
			{
				continue;
			}
			CFirstRectangle.SetLeftTopX(vData[0]);
			CFirstRectangle.SetLeftTopY(vData[1]);
			CFirstRectangle.SetWidht(vData[2]);
			CFirstRectangle.SetHeight(vData[3]);
			vData.clear();
		}
		else if (strstr(sCommand.c_str(), "Move"))
		{
			vData = fVectorWithData(sCommand);
			if (vData.size() != 2)
			{
				continue;
			}
			CFirstRectangle.Move(vData[0], vData[1]);
			vData.clear();
		}
		else if (strstr(sCommand.c_str(), "Scale"))
		{
			vData = fVectorWithData(sCommand);
			if (vData.size() != 2)
			{
				continue;
			}
			CFirstRectangle.Scale(vData[0], vData[1]);
			vData.clear();
		}
	}

	////////////////////////////  2 прямоугольник

	while (!finSecondRectangle.eof())
	{
		getline(finSecondRectangle, sCommand);
		if (strstr(sCommand.c_str(), "Rectangle"))
		{
			vData = fVectorWithData(sCommand);
			if (vData.size() != 4)
			{
				continue;
			}
			CSecondRectangle.SetLeftTopX(vData[0]);
			CSecondRectangle.SetLeftTopY(vData[1]);
			CSecondRectangle.SetWidht(vData[2]);
			CSecondRectangle.SetHeight(vData[3]);
			vData.clear();
		}
		else if (strstr(sCommand.c_str(), "Move"))
		{
			vData = fVectorWithData(sCommand);
			if (vData.size() != 2)
			{
				continue;
			}
			CSecondRectangle.Move(vData[0], vData[1]);
			vData.clear();
		}
		else if (strstr(sCommand.c_str(), "Scale"))
		{
			vData = fVectorWithData(sCommand);
			if (vData.size() != 2)
			{
				continue;
			}
			CSecondRectangle.Scale(vData[0], vData[1]);
			vData.clear();
		}
	}


	CFirstRectangle.ShowData();
	cout << endl;
	CSecondRectangle.ShowData();


	CFirstRectangle.~CRectangle();
	CSecondRectangle.~CRectangle();
	finFirstRectangle.close();
	finSecondRectangle.close();

	return 0;
}

