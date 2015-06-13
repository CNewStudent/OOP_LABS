#include "stdafx.h"
#include "../OOP_L5/CVector3D.h"
#include "../OOP_L5/Functions.h"

BOOST_AUTO_TEST_CASE(Init)
{
	CVector3D vectorOne;
	CVector3D vectorTwo(10, 10, 5);

	BOOST_CHECK(vectorOne.m_x == 0);
	BOOST_CHECK(vectorOne.m_y == 0);
	BOOST_CHECK(vectorOne.m_z == 0);
	BOOST_CHECK(vectorOne.GetLength() == 0);

	BOOST_CHECK(vectorTwo.m_x == 10);
	BOOST_CHECK(vectorTwo.m_y == 10);
	BOOST_CHECK(vectorTwo.m_z == 5);
	BOOST_CHECK(vectorTwo.GetLength() == 15);
}

BOOST_AUTO_TEST_CASE(UnaryPlusAndMinus)
{
	CVector3D vectorOne(-3,-6,-8);
	CVector3D vectorTwo(3, 6, 8);
	CVector3D vectorThree(5, 5, 5);

	BOOST_CHECK((-vectorOne) == vectorTwo);
	BOOST_CHECK(vectorTwo == (+vectorTwo));
	BOOST_CHECK(vectorTwo != vectorThree);
}

BOOST_AUTO_TEST_CASE(BinaryPlusAndMinus)
{
	CVector3D vectorOne(5, 5, 5);
	CVector3D vectorTwo(3, 3, 3);

	CVector3D vectorResultPlus = vectorOne + vectorTwo;

	BOOST_CHECK(vectorResultPlus.m_x == 8);
	BOOST_CHECK(vectorResultPlus.m_y == 8);
	BOOST_CHECK(vectorResultPlus.m_z == 8);

	CVector3D vectorResultMinus = vectorOne - vectorTwo;
	BOOST_CHECK(vectorResultMinus.m_x == 2);
	BOOST_CHECK(vectorResultMinus.m_y == 2);
	BOOST_CHECK(vectorResultMinus.m_z == 2);

}

BOOST_AUTO_TEST_CASE(DualOperatorPlusMinus)
{
	CVector3D vectorOne(10, 10, 5); //15
	CVector3D vectorTwo(9, 2, 6); // 11
	CVector3D vectorThree(2, 6, 9); //11
	CVector3D vectorFour(10, 5, 10); //15

	CVector3D vectorResultPlus = vectorOne += vectorTwo;
	BOOST_CHECK(vectorResultPlus.GetLength() == 26);

	CVector3D vectorResultMinus = vectorThree -= vectorFour;
	BOOST_CHECK(vectorResultMinus.GetLength() == -4);
}

BOOST_AUTO_TEST_CASE(ActionWithScalar)
{
	CVector3D vectorOne(10, 10, 5); //15
	CVector3D vectorTwo(9, 2, 6); // 11

	CVector3D vectorResultMultiply = vectorOne * 4;
	CVector3D vectorResultReverseMultiply = 4 * vectorTwo;
	
	BOOST_CHECK(vectorResultMultiply.m_x == 40);
	BOOST_CHECK(vectorResultMultiply.m_y == 40);
	BOOST_CHECK(vectorResultMultiply.m_z == 20);

	BOOST_CHECK(vectorResultReverseMultiply.m_x == 36);
	BOOST_CHECK(vectorResultReverseMultiply.m_y == 8);
	BOOST_CHECK(vectorResultReverseMultiply.m_z == 24);
}

BOOST_AUTO_TEST_CASE(ActionWithScalarWithDual)
{
	CVector3D vectorOne(10, 10, 5); //15
	CVector3D vectorTwo(9, 2, 6); // 11

	CVector3D vectorResultMultiply =  vectorOne /= 5;
	CVector3D vectorResultShare = vectorTwo *= 10;

	BOOST_CHECK(vectorResultMultiply.m_x == 2);
	BOOST_CHECK(vectorResultMultiply.m_y == 2);
	BOOST_CHECK(vectorResultMultiply.m_z == 1);

	BOOST_CHECK(vectorResultShare.m_x == 90);
	BOOST_CHECK(vectorResultShare.m_y == 20);
	BOOST_CHECK(vectorResultShare.m_z == 60);
}