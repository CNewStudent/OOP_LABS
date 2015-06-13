#include "stdafx.h"
#include "Functions.h"

double DotProduct(CVector3D const & v1, CVector3D const & v2)
{
	return v1.m_x * v2.m_x + v1.m_y * v2.m_y + v1.m_z * v2.m_z;
}


CVector3D CrossProduct(CVector3D const & v1, CVector3D const & v2)
{
	return CVector3D(v1.m_y * v2.m_z - v1.m_z * v2.m_y,
		v1.m_z * v2.m_x - v1.m_x * v2.m_z,
		v1.m_x * v2.m_y - v1.m_y * v2.m_x);
}