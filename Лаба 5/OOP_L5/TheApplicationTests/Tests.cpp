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
}

BOOST_AUTO_TEST_CASE(CheckComparison)
{
	CVector3D const vectorTwo(3, 6, 8);
	CVector3D const vectorThree(5, 5, 5);
	CVector3D const vectorOne(3, 6, 8);

	BOOST_CHECK(vectorTwo != vectorThree);
	BOOST_CHECK(vectorOne == vectorTwo);
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

	vectorOne += vectorTwo;
	BOOST_CHECK(vectorOne.m_x == 19);
	BOOST_CHECK(vectorOne.m_y == 12);
	BOOST_CHECK(vectorOne.m_z == 11);
	
	vectorThree -= vectorFour;
	BOOST_CHECK(vectorThree.m_x == -8);
	BOOST_CHECK(vectorThree.m_y == 1);
	BOOST_CHECK(vectorThree.m_z == -1);	
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
	CVector3D vectorOne(10, 6, -3); //15
	CVector3D vectorTwo(9, -2, 6.1); // 11


	const double EPSILON = 1e-10;
	BOOST_CHECK_EQUAL(&(vectorOne /= 5), &vectorOne);
	BOOST_CHECK_CLOSE_FRACTION(vectorOne.m_x, 2, EPSILON);
	BOOST_CHECK_CLOSE_FRACTION(vectorOne.m_y, 1.2, EPSILON);
	BOOST_CHECK_CLOSE_FRACTION(vectorOne.m_z, -0.6, EPSILON);

	BOOST_CHECK_EQUAL(&(vectorTwo *= 2), &vectorTwo);
	BOOST_CHECK_CLOSE_FRACTION(vectorTwo.m_x, 18, EPSILON);
	BOOST_CHECK_CLOSE_FRACTION(vectorTwo.m_y, -4, EPSILON);
	BOOST_CHECK_CLOSE_FRACTION(vectorTwo.m_z, 12.2, EPSILON);

}

BOOST_AUTO_TEST_CASE(CheckDotProduct)
{
	CVector3D vectorOne(2, 3, 2);
	CVector3D vectorTwo(5, 5, 3);
	double result = DotProduct(vectorOne, vectorTwo);
	BOOST_CHECK(result == 31);

}

BOOST_AUTO_TEST_CASE(CheckCrossProduct)
{
	CVector3D vectorOne(2, 3, 2);
	CVector3D vectorTwo(5, 5, 3);

	CVector3D result = CrossProduct(vectorOne, vectorTwo);
	BOOST_CHECK(result.m_x == -1);
	BOOST_CHECK(result.m_y == 4);
	BOOST_CHECK(result.m_z == -5);

	BOOST_CHECK(CrossProduct(CVector3D(1, 0, 0), CVector3D(0, 1, 0)) == CVector3D(0, 0, 1));
}

BOOST_AUTO_TEST_CASE(CheckNorm)
{
	CVector3D vector;
	vector.Normalize();
	BOOST_CHECK_EQUAL(vector.GetLength(), 0.0);

	CVector3D vector2(10, 10, 5);
	auto vector2copy(vector2);
	vector2copy.Normalize();
	BOOST_CHECK_CLOSE(vector2copy.GetLength(), 1.0, 1e-10);

	BOOST_CHECK_CLOSE(DotProduct(vector2, vector2copy) / vector2.GetLength(), 1.0, 1e-10);
}