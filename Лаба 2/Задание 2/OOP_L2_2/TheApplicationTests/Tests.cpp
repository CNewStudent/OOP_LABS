#include "stdafx.h"
#include "../OOP_L2_2/RemoveSpace.h"

using namespace std;

	
BOOST_AUTO_TEST_CASE(EmptyString)
{	
	string str_One, str_Two;
	str_One = "";
	str_Two = RemoveExtraSpaces(str_One);
	BOOST_CHECK(str_Two.size() == 0);
}

BOOST_AUTO_TEST_CASE(OneSpace)
{
	string str_One, str_Two;
	str_One = " ";
	str_Two = RemoveExtraSpaces(str_One);
	BOOST_CHECK(str_Two.size() == 0);
}

BOOST_AUTO_TEST_CASE(SpaceBegin)
{
	string str_One, str_Two;
	str_One = "       test";
	str_Two = RemoveExtraSpaces(str_One);
	BOOST_CHECK(str_Two.size() == 4);
}

BOOST_AUTO_TEST_CASE(SpaceEnd)
{
	string str_One, str_Two;
	str_One = " test    ";
	str_Two = RemoveExtraSpaces(str_One);
	BOOST_CHECK(str_Two.size() == 4);
}

BOOST_AUTO_TEST_CASE(MuchSpace)
{
	string str_One, str_Two;
	str_One = " t  t  t  ";
	str_Two = RemoveExtraSpaces(str_One);
	BOOST_CHECK(str_Two.size() == 5);
}