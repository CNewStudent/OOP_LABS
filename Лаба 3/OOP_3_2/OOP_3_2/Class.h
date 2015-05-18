#include "stdafx.h"



class CRectangle
{
public:
	CRectangle(int x, int y, int widht, int height);
	~CRectangle();
	void Move(int dx, int dy);
	void Scale(int sx, int sy);
	bool Intersect(CRectangle & other);
	int GetArea() const;
	int GetPerimetr() const;
	int GetCoordinateLeftTopX();
	int GetCoordinateLeftTopY();
	int GetCoordinateRightBottomX();
	int GetCoordinateRightBottomY();
	int GetWidht();
	int GetHight();
	void SetWidht(int widht);
	void SetHeight(int height);
	void SetLeftTopX(int x);
	void SetLeftTopY(int y);
	void ShowData();
private:
	int m_height, m_widht, m_LeftTopX, m_LeftTopY;	
};

