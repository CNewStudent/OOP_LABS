#define _USE_MATH_DEFINES

#include "stdafx.h"
#include <math.h>
#include <string>
#include <sstream>


class IShape
{
public:
	virtual std::string ToString()const=0;
	virtual double GetArea()const= 0;
	virtual double GetPerimetr()const= 0;
	virtual ~IShape(){};
};

class CPoint : public IShape
{
public:
	CPoint(double x, double y)
		:m_x(x), m_y(y){}
	virtual double GetArea() const
	{
		return 0;
	}
	virtual double GetPerimetr() const
	{
		return 0;
	}
	virtual std::string ToString() const
	{
		std::string info = "";
		std::ostringstream ost;
		ost  << "<"<< m_x << "," << m_y << ">";
		info += "Point ";
		info += ost.str();
		return info;
	}
	double GetX() const
	{
		return m_x;
	}
	double GetY() const
	{
		return m_y;
	}
private:
	double m_x, m_y;
};


class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint const & p1, CPoint const & p2)
		:m_p1(p1), m_p2(p2){}
	CLineSegment(double x1, double y1, double x2, double y2)
		:m_p1(x1, y1), m_p2(x2, y2){}

	virtual std::string ToString()const
	{
		//return "LineSegment";
		std::string info = "";
		std::ostringstream ost;
		ost << "<" << m_p1.GetX() << "," << m_p1.GetY() << "; " << m_p2.GetX() << "," << m_p2.GetY() << ">";
		info += "LineSigment ";
		info += ost.str();
		return info;
	}
	virtual double GetArea()const
	{
		return 0;
	}
	virtual double GetPerimetr()const
	{
		return sqrt(pow((m_p2.GetX() - m_p1.GetX()), 2) + pow((m_p2.GetY() - m_p1.GetY()), 2));
	}
	double GetLength()const
	{
		return sqrt(pow((m_p1.GetX() - m_p2.GetX()), 2) + pow((m_p1.GetY() - m_p2.GetY()), 2));
	}
private:
	CPoint m_p1, m_p2;
};


class ISolidShape: public IShape 
{
public:
	virtual std::string GetColour() const = 0;
};

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint const & p, double length, double width)
		:m_p(p), m_length(length), m_widht(width){}
	CRectangle(double x, double y, double length, double width)
		:m_p(x,y), m_length(length), m_widht(width){}

	virtual std::string ToString()const
	{
		//return "Rectangle";
		std::string info = "";
		std::ostringstream ost;
		ost << "<"<< m_p.GetX() << "," << m_p.GetY() << ">," << m_length << "x" << m_widht;
		info += "Rectangle ";
		info += ost.str();
		return info;
	}
	virtual double GetArea()const
	{
		return m_length * m_widht;
	}
	virtual double GetPerimetr()const
	{
		return (m_length + m_widht) * 2;
	}
	virtual std::string GetColour()const
	{
		return "Red";
	}
private:
	CPoint m_p;
	double m_length, m_widht;
};

class CTriangle : public ISolidShape
{
public:
	CTriangle(CPoint const & p1, CPoint const & p2, CPoint const & p3)
		:m_p1(p1), m_p2(p2), m_p3(p3){}
	CTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
		:m_p1(x1, y1), m_p2(x2, y2), m_p3(x3, y3){}

	virtual std::string ToString()const
	{
		//return "Triangle";
		std::string info = "";
		std::ostringstream ost;
		ost << "<" << m_p1.GetX() << "," << m_p1.GetY() << "; " << m_p2.GetX() << "," << m_p2.GetY() << "; " << m_p3.GetX() << "," << m_p3.GetY() << ">";
		info += "Triangle ";
		info += ost.str();
		return info;
	}
	virtual double GetArea()const
	{
		return abs(0.5 * ((m_p1.GetX() - m_p3.GetX()) * (m_p2.GetY() - m_p3.GetY()) - (m_p2.GetX() - m_p3.GetX()) * (m_p1.GetY() - m_p3.GetY())));
	}
	virtual double GetPerimetr()const
	{
		double AB, BC, CA;
		AB = sqrt(pow((m_p2.GetX() - m_p1.GetX()), 2) + pow((m_p2.GetY() - m_p1.GetY()), 2));
		BC = sqrt(pow((m_p3.GetX() - m_p2.GetX()), 2) + pow((m_p3.GetY() - m_p2.GetY()), 2));
		CA = sqrt(pow((m_p3.GetX() - m_p1.GetX()), 2) + pow((m_p3.GetY() - m_p1.GetY()), 2));
		return (AB + BC + CA) / 2;
	}
	virtual std::string GetColour()const
	{
		return "Yellow";
	}
private:
	CPoint m_p1, m_p2, m_p3;
};

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint const & p, double radius)
		:m_p(p), m_radius(radius){}
	CCircle(double x ,double y, double radius)
		:m_p(x, y), m_radius(radius){}

	virtual std::string ToString()const
	{
		 //return "Circle";
		std::string info = "";
		std::ostringstream ost;
		ost << "<" << m_p.GetX() << "," << m_p.GetY() << "> Radius=" << m_radius ;
		info += "Circle ";
		info += ost.str();
		return info;
	}
	virtual double GetArea()const
	{
		return M_PI * pow(m_radius,2);
	}
	virtual double GetPerimetr()const
	{
		return 2 * M_PI * m_radius;
	}
	virtual std::string GetColour()const
	{
		return "Green";
	}
private:
	CPoint m_p;
	double m_radius;
};