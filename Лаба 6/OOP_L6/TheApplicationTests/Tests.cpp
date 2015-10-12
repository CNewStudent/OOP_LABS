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
	CTriangle triangle(3, 4, 5);
	//BOOST_CHECK((triangle.GetArea() - 15.5885) < DBL_MIN);
	BOOST_CHECK_CLOSE(triangle.GetArea(), 6, 1e-10);
	BOOST_CHECK(triangle.GetPerimeter() == 12);
}

BOOST_AUTO_TEST_CASE(NegativeSide)
{
	BOOST_CHECK_THROW((CTriangle(0, 0, -1)), std::invalid_argument);
	BOOST_CHECK_THROW((CTriangle(0, -1, 0)), std::invalid_argument);
	BOOST_CHECK_THROW((CTriangle(-1, 0, 0)), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(WrongSideLength)
{
	BOOST_CHECK_THROW((CTriangle(1, 2, 4)), std::domain_error);
	BOOST_CHECK_THROW((CTriangle(4, 2, 1)), std::domain_error);
	BOOST_CHECK_THROW((CTriangle(2, 4, 1)), std::domain_error);
}

BOOST_AUTO_TEST_CASE(DegenerateTriangle)
{
	BOOST_CHECK_NO_THROW((CTriangle(0, 0, 0)));
	BOOST_CHECK_NO_THROW((CTriangle(2, 3, 5)));
	BOOST_CHECK_NO_THROW((CTriangle(5, 3, 2)));
	BOOST_CHECK_NO_THROW((CTriangle(2, 5, 3)));
	BOOST_CHECK_NO_THROW((CTriangle(0, 3, 3)));
	BOOST_CHECK_NO_THROW((CTriangle(3, 3, 0)));
	BOOST_CHECK_NO_THROW((CTriangle(3, 0, 3)));
}


