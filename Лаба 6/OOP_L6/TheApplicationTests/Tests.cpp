#include "stdafx.h"
#include "../OOP_L6/CTriangle.h"
#include <float.h>

BOOST_AUTO_TEST_CASE(Init)
{
	CTriangle triangle(4, 6, 7);
	BOOST_CHECK(triangle.GetSide1() == 4);
	BOOST_CHECK(triangle.GetSide2() == 6);
	BOOST_CHECK(triangle.GetSide3() == 7);
}



BOOST_AUTO_TEST_CASE(AreaAndPerimetr)
{
	CTriangle triangle(6, 6, 6);
	BOOST_CHECK((triangle.GetArea() - 15.5885) < DBL_MIN);
	BOOST_CHECK(triangle.GetPerimeter() == 18);
}

BOOST_AUTO_TEST_CASE(NegativeDigit)
{
	try
	{
		CTriangle triangle(6, 6, -6);
	}
	catch (std::logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(WrongSizeSide)
{
	try
	{
		CTriangle triangle(2, 2, 5);
	}
	catch (std::logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}