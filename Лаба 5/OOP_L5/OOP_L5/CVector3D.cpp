#include "stdafx.h"
#include "CVector3D.h"



CVector3D::CVector3D()
	:m_x(0), m_y(0), m_z(0)
{
	m_length = 0;
}

CVector3D::CVector3D(double x, double y, double z)
	: m_x(x), m_y(y), m_z(z)
{
	m_length = sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

double CVector3D::GetLength()const
{
	return m_length;
}

void CVector3D::Normalize()
{
	m_x /= m_length;
	m_y /= m_length;
	m_z /= m_length;
}

void CVector3D::SetLength(double len, bool sign)
{
	if (sign)
	{
		m_length += len;
	}
	else
	{
		m_length -= len;
	}
}


//CVector3D const operator -(CVector3D const & v1)
//{
//	return CVector3D(v1.m_x * -1, v1.m_y * -1, v1.m_z * -1);
//}

//CVector3D const operator +(CVector3D const & v1)
//{
//	return v1;
//}

//CVector3D const operator +(CVector3D const & vector1, CVector3D const & vector2)
//{
//	return CVector3D(vector1.m_x + vector2.m_x, vector1.m_y + vector2.m_y, vector1.m_z + vector2.m_z);
//}

//CVector3D const operator -(CVector3D const & vector1, CVector3D const & vector2)
//{
//	return CVector3D(vector1.m_x - vector2.m_x, vector1.m_y - vector2.m_y, vector1.m_z - vector2.m_z);
//}

//CVector3D  & operator +=(CVector3D & vector1, CVector3D const & vector2)
//{
//	vector1.SetLength(vector2.GetLength(), true);
//
//	return vector1;
//}

//CVector3D & operator -=(CVector3D & vector1, CVector3D const & vector2)
//{
//	vector1.SetLength(vector2.GetLength(), false);
//
//	return vector1;
//}

CVector3D const operator *(double scalar, CVector3D const & vector1)
{
	return CVector3D(scalar * vector1.m_x, scalar * vector1.m_y, scalar * vector1.m_z);
}

//CVector3D const operator *(CVector3D const & vector1, double scalar)
//{
//	return CVector3D(scalar * vector1.m_x, scalar * vector1.m_y, scalar * vector1.m_z);
//}

//CVector3D const operator /(CVector3D const & vector1, double scalar)
//{
//	return CVector3D(vector1.m_x / scalar, vector1.m_y / scalar, vector1.m_z / scalar);
//}

//CVector3D & operator *=(CVector3D const & vector1, double scalar)
//{
//	return CVector3D(vector1.m_x * scalar, vector1.m_y * scalar, vector1.m_z * scalar);
//}
//
//CVector3D & operator /=(CVector3D const & vector1, double scalar)
//{
//	return CVector3D(vector1.m_x / scalar, vector1.m_y / scalar, vector1.m_z / scalar);
//}


//bool CVector3D::operator==(CVector3D const & vector2)
//{
//	double x = abs(m_x - vector2.m_x);
//	double y = abs(m_y - vector2.m_y);
//	double z = abs(m_z - vector2.m_z);
//
//	return (x <= DBL_EPSILON) && (y <= DBL_EPSILON) && (z <= DBL_EPSILON);
//}

//bool CVector3D::operator!=(CVector3D const & vector2)
//{
//	double x = abs(m_x - vector2.m_x);
//	double y = abs(m_y - vector2.m_y);
//	double z = abs(m_z - vector2.m_z);
//
//	return (x > DBL_EPSILON) || (y > DBL_EPSILON) || (z > DBL_EPSILON);
//}


