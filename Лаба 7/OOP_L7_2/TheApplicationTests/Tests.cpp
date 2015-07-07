#include "stdafx.h"
#include "../OOP_L7_2/CMyArray.h"
#include <float.h>
#include <stdexcept>


BOOST_AUTO_TEST_CASE(CheckSize)
{
	
		CMyArray<int> intArray;

		BOOST_CHECK(intArray.Size() == 0);

		intArray.Add(3);
		intArray.Add(6);

		BOOST_CHECK(intArray.Size() == 2);
}

BOOST_AUTO_TEST_CASE(CheckIndex)
{
	CMyArray<int> intArray;

	intArray.Add(3);
	intArray.Add(6);

	int Error;

	BOOST_CHECK(intArray[0] == 3);
	BOOST_CHECK(intArray[1] == 6);
	BOOST_CHECK_THROW(Error = intArray[10], out_of_range);
}

BOOST_AUTO_TEST_CASE(CheckClear)
{
	CMyArray<int> intArray;

	intArray.Add(3);
	intArray.Add(6);

	intArray.Clear();

	BOOST_CHECK(intArray.Size() == 0);
}

BOOST_AUTO_TEST_CASE(CheckResize)
{
	CMyArray<int> intArray;

	intArray.Add(3);

	intArray.Resize(3);
	BOOST_CHECK(intArray[2] == 0);
}

BOOST_AUTO_TEST_CASE(CheckAssigned)
{
	CMyArray<int> intArray;
	intArray.Add(3);
	intArray.Add(5);

	CMyArray<int> intArraySecond = intArray;

	BOOST_CHECK(intArraySecond.Size() == 2);
	BOOST_CHECK(intArraySecond[0] == 3);

}

BOOST_AUTO_TEST_CASE(CheckCopy)
{
	CMyArray<std::string> strArray;
	strArray.Add("Hello");
	strArray.Add("World");

	CMyArray<std::string> strArraySecond(strArray);

	BOOST_CHECK(strArraySecond.Size() == 2);
	BOOST_CHECK(strArraySecond[0] == "Hello");

}