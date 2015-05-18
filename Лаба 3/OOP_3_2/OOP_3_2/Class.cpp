#include "stdafx.h"
#include "Class.h"
#include <iostream>

using namespace std;

CRectangle::CRectangle(int x, int y, int widht, int height)
	:m_height(height), m_widht(widht), m_LeftTopX(x), m_LeftTopY(y)
{
	m_height = (height <= 0) ? 0 : height;
	m_widht = (widht <= 0) ? 0 : widht;
	m_LeftTopX = (x <= 0) ? 0 : x;
	m_LeftTopY = (y <= 0) ? 0 : y;
}

CRectangle::~CRectangle()
{
}

bool CRectangle::Intersect(CRectangle & other)
{	
	if ((abs(m_LeftTopX - other.GetCoordinateLeftTopX()) <= m_widht) && (abs(m_LeftTopY - other.GetCoordinateLeftTopY()) <= m_height))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CRectangle::Scale(int sx, int sy)
{
	int nRightBottomX = (sx <= 0) ? 0 : sx;
	int nRightBottomY = (sx <= 0) ? 0 : sy;

	m_widht = abs(m_LeftTopX - nRightBottomX);
	m_height = abs(m_LeftTopY - nRightBottomY);
}

void CRectangle::Move(int dx, int dy)
{
	m_LeftTopX = (dx <= 0) ? 0 : dx;
	m_LeftTopY = (dy <= 0) ? 0 : dx;
}

int CRectangle::GetArea()const
{
	return m_height * m_widht;
}

int CRectangle::GetPerimetr()const
{
	return (m_widht + m_height) * 2;
}

int CRectangle::GetCoordinateLeftTopX()
{
	return m_LeftTopX;
}

int CRectangle::GetCoordinateLeftTopY()
{
	return m_LeftTopY;
}

int CRectangle::GetCoordinateRightBottomX()
{
	return m_LeftTopX + m_widht;
}

int CRectangle::GetCoordinateRightBottomY()
{
	return m_LeftTopY + m_height;
}

int CRectangle::GetHight()
{
	return m_height;
}

int CRectangle::GetWidht()
{
	return m_widht;
}

void CRectangle::SetHeight(int height)
{
	m_height = (height <= 0) ? 0 : height;
}

void CRectangle::SetWidht(int widht)
{
	m_widht = (widht <= 0) ? 0 : widht;
}

void CRectangle::SetLeftTopX(int x)
{
	m_LeftTopX = (x <= 0) ? 0 : x;
}

void CRectangle::SetLeftTopY(int y)
{
	m_LeftTopY = (y <= 0) ? 0 : y;
}

void CRectangle::ShowData()
{
	cout << "Left Top: " << GetCoordinateLeftTopX() << ", " << GetCoordinateLeftTopY() << endl;
	cout << "Size: " << GetWidht() << " * " << GetHight() << " = " << GetArea() << endl;
	cout << "Right Bottom: " << GetCoordinateRightBottomX() << ", " << GetCoordinateRightBottomY() << endl;
	cout << "Area: " << GetArea() << endl;
	cout << "Perimetr: " << GetPerimetr() << endl;
}