#pragma once
#include<vector>

using namespace std;

template < typename T, typename Less>
bool FindMax(vector<T> const & arr, T & maxValue, Less less(T const &param1, T const &param2))
{
	if (arr.size() == 0)
	{
		return false;
	}

	maxValue = arr[0];
	for (int i = 0; i < arr.size(); i++)
	{
		if (less(arr[i], maxValue))
			maxValue = arr[i];
	}
	return true;
}