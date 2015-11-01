#include "stdafx.h"
#include "../OOP_L4/Classes.h"


BOOST_AUTO_TEST_CASE(TestPoint)
{
	CPoint point(4, 5);
	BOOST_CHECK(point.GetArea() == 0);
	BOOST_CHECK(point.GetPerimetr() == 0);
	BOOST_CHECK(point.GetX() == 4);
	BOOST_CHECK(point.GetY() == 5);
	BOOST_CHECK(point.ToString() == "Point <4,5>");
}

BOOST_AUTO_TEST_CASE(TestLineSigment)
{
	CLineSegment Line(0, 0, 4, 4);
	CPoint point_1(0, 0);
	CPoint point_2(4, 4);
	CLineSegment Line_2(point_1, point_2);
	BOOST_CHECK(Line.GetArea() == 0);
	BOOST_CHECK_CLOSE(Line.GetPerimetr(), 5.6568, 0.1);
	BOOST_CHECK(Line.ToString() == "LineSigment <0,0; 4,4>");

	BOOST_CHECK(Line_2.GetArea() == 0);
	BOOST_CHECK_CLOSE(Line_2.GetPerimetr(), 5.6568, 0.1);
	BOOST_CHECK(Line_2.ToString() == "LineSigment <0,0; 4,4>");
}

BOOST_AUTO_TEST_CASE(TestCircle)
{
	CCircle Circle(0, 0, 10);
	
	CPoint point(0, 0);
	CCircle Circle_2(point, 10);


	BOOST_CHECK(Circle.GetColour() == "Green");
	BOOST_CHECK_CLOSE(Circle.GetArea(), 314.16, 0.1);
	BOOST_CHECK_CLOSE(Circle.GetPerimetr(), 62.83, 0.1);
	BOOST_CHECK(Circle.ToString() == "Circle <0,0> Radius=10");

	BOOST_CHECK(Circle_2.GetColour() == "Green");
	BOOST_CHECK_CLOSE(Circle_2.GetArea(), 314.16, 0.1);
	BOOST_CHECK_CLOSE(Circle_2.GetPerimetr(), 62.83, 0.1);
	BOOST_CHECK(Circle_2.ToString() == "Circle <0,0> Radius=10");
}


BOOST_AUTO_TEST_CASE(TestTriangle)
{
	CTriangle triangle(0,0,5,0,0,5);
	CTriangle triangle_2(0, 0, 0, 3, 5, 0);

	CPoint point_1(0, 0);
	CPoint point_2(5, 0);
	CPoint point_3(0, 5);
	CTriangle triangle_3(point_1, point_2, point_3);

	BOOST_CHECK(triangle.GetColour() == "Yellow");
	BOOST_CHECK(triangle_2.GetColour() == "Yellow");
	BOOST_CHECK(triangle_3.GetColour() == "Yellow");

	BOOST_CHECK_CLOSE(triangle.GetArea(), 12.5, 0.1);
	BOOST_CHECK_CLOSE(triangle_2.GetArea(), 7.5, 0.1);
	BOOST_CHECK_CLOSE(triangle_3.GetArea(), 12.5, 0.1);
	BOOST_CHECK_CLOSE(triangle.GetPerimetr(), 8.536, 0.1);
	BOOST_CHECK_CLOSE(triangle_2.GetPerimetr(), 6.916, 0.1);
	BOOST_CHECK_CLOSE(triangle_3.GetPerimetr(), 8.536, 0.1);

	BOOST_CHECK(triangle.ToString() == "Triangle <0,0; 5,0; 0,5>");
}


BOOST_AUTO_TEST_CASE(TestRectangle)
{
	CRectangle rectangle(0, 0, 4, 5);

	CPoint point(0, 0);
	CRectangle rectangle_2(point, 4, 5);

	BOOST_CHECK(rectangle.GetArea() == 20);
	BOOST_CHECK(rectangle.GetPerimetr() == 18);

	BOOST_CHECK(rectangle_2.GetArea() == 20);
	BOOST_CHECK(rectangle_2.GetPerimetr() == 18);

	BOOST_CHECK(rectangle.ToString() == "Rectangle <0,0>,4x5");
	BOOST_CHECK(rectangle_2.ToString() == "Rectangle <0,0>,4x5");
}
