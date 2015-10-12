#pragma once
#include<vector>

using namespace std;

template <typename T, typename Less = std::less<T>>
bool FindMax(vector<T> const & arr, T & maxValue, const Less & less = Less())
{
	if (arr.size() == 0)
	{
		return false;
	}

	//maxValue = arr[0];
	size_t index = 0;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (less(arr[index], arr[i]))
			//maxValue = arr[i];
			index = i;
	}

	maxValue = arr[index];

	return true;
}

