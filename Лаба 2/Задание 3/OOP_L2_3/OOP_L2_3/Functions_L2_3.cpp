#include "stdafx.h"
#include "Functions_L2_3.h"

#include <iostream>


map<string, int> FillInDictionary(string strWords)
{
	map<string, int> resultDictionary;
	string word = "";
	strWords += " ";
	

	
	for (unsigned int i = 0; i < strWords.size(); i++)
	{
		int intChar = strWords[i];
		if ((intChar >= 'A' && intChar <= 'Z') || (intChar >= 'a' && intChar <= 'z'))
		{
			word += strWords[i];
		}
		else
		{
			if (word != "")
			{
				map<string, int>::iterator it = resultDictionary.find(word);
				if (it != resultDictionary.end())
				{
					resultDictionary[word]++;
				}
				else
				{
					resultDictionary[word] = 1;
				}
			}
			word = "";
		}
	}

	return resultDictionary;
}

void PrintResult(map<string, int> &dictionary)
{
	map<string, int>::iterator it = dictionary.begin();
	map<string, int>::iterator itEnd = dictionary.end();
	for (; it != itEnd; it++)
	{
		cout << "word: " << (*it).first << " count: " << (*it).second << endl;
	}
}