#include "stdafx.h"
#include "CTriangle.h"
#include <cmath>
#include <stdexcept>

CTriangle::CTriangle(double side1, double side2, double side3)
	:m_side1(side1), m_side2(side2), m_side3(side3)
{
	if (m_side1 < 0 || m_side2 < 0 || m_side3 < 0)
	{
		throw std::invalid_argument("sides must be >= 0");
	}
	if (m_side1 >(m_side2 + m_side3) || m_side2 > (m_side1 + m_side3) || m_side3 > (m_side2 + m_side1))
	{
		throw std::domain_error("incorrectly set side");
	}
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetSide1()const
{
	return m_side1;
}

double CTriangle::GetSide2()const
{
	return m_side2;
}

double CTriangle::GetSide3()const
{
	return m_side3;
}

double CTriangle::GetPerimeter()const
{
	return m_side1 + m_side2 + m_side3;
}

double CTriangle::GetArea()const
{
	double p = GetPerimeter() / 2;
	return sqrt(p * (p - m_side1) * (p - m_side2) * (p - m_side3));
}