#pragma once
#include <cmath>
#include <float.h>
#include <fstream>
#include <string>
#include <vector>

class CVector3D
{
public:
	CVector3D();
	CVector3D(double x0, double y0, double z0);
	double GetLength()const;
	void Normalize();
	void SetLength(double len, bool sign);
	
	CVector3D const operator -()const
	{
		return CVector3D(-m_x, -m_y, - m_z);
	}
	CVector3D const operator +()const
	{
		return *this;
	}
	CVector3D const operator +(CVector3D const & vector2)const
	{
		return CVector3D(m_x + vector2.m_x, m_y + vector2.m_y, m_z + vector2.m_z);
	}
	CVector3D const operator -(CVector3D const & vector2)const
	{
		return CVector3D(m_x - vector2.m_x, m_y - vector2.m_y, m_z - vector2.m_z);
	}
	CVector3D  & operator +=(CVector3D const & vector2)
	{
		m_length += vector2.m_length;

		return *this;
	}
	CVector3D & operator -=(CVector3D const & vector2)
	{
		m_length -= vector2.m_length;

		return *this;
	}
	CVector3D const operator *(double scalar)const
	{
		return CVector3D(scalar * m_x, scalar * m_y, scalar * m_z);
	}
	CVector3D const operator /(double scalar)const
	{
		return CVector3D(m_x / scalar, m_y / scalar, m_z / scalar);
	}
	CVector3D & operator *=(double scalar)const
	{
		return CVector3D(m_x * scalar, m_y * scalar, m_z * scalar);
	}
	CVector3D & operator /=(double scalar)const
	{
		return CVector3D(m_x / scalar, m_y / scalar, m_z / scalar);
	}
	
	CVector3D const friend operator *(double scalar, CVector3D const & vector1);
	bool operator ==(CVector3D const & vector2)const
	{
		double x = abs(m_x - vector2.m_x);
		double y = abs(m_y - vector2.m_y);
		double z = abs(m_z - vector2.m_z);

		return (x <= DBL_EPSILON) && (y <= DBL_EPSILON) && (z <= DBL_EPSILON);
	}
	bool operator !=(CVector3D const & vector2)
	{
		double x = abs(m_x - vector2.m_x);
		double y = abs(m_y - vector2.m_y);
		double z = abs(m_z - vector2.m_z);

		return (x > DBL_EPSILON) || (y > DBL_EPSILON) || (z > DBL_EPSILON);
	}
	/*ostream& operator<<(ostream& os)
	{
		os << m_x << ", " << m_y << ", " << m_z;
		return os;
	}
	*/
	

	double m_x, m_y, m_z;
private:		
	double m_length;
};