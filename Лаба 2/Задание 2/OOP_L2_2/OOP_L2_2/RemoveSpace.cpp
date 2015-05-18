#include "stdafx.h"
#include "RemoveSpace.h" 

 
using namespace std;

string RemoveExtraSpaces(string const &arg)
{
	string result;
	result.reserve(arg.size());

	if (arg.size() == 0)
	{
		result = "";
		return result;
	}
	const char *space = " ";
	
	for (unsigned int i = 0; i < arg.size(); i++)
	{
		if (arg[i] == *space)
		{
			while (arg[i + 1] == *space)
			{
				i++;
			}
			result.push_back(arg[i]);
		}
		else
		{
			result.push_back(arg[i]);
		}
	}

	if (result[result.size() - 1] == *space)
	{
		result.pop_back();
	}
	if (result[0] == *space)
	{
		result.erase(result.begin());
	}
	return result;
}

