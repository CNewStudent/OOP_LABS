#include "stdafx.h"
#include "RemoveSpace.h" 

 
using namespace std;

string RemoveExtraSpaces(string const &arg)
{
	string result;
	bool isSpaces = false;
	
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (arg[i] != ' ')
		{
			result += arg[i];
			isSpaces = true;
		}

		if (isSpaces && arg[i] == ' ')
		{
			result += arg[i];
			isSpaces = false;
		}
	}
	
	if (result.empty())
	{
		return result;
	}
	if (result.back() == ' ')
	{
		result.pop_back();
	}
	return result;
}

