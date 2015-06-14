// OOP_L6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CTriangle.h"
#include <iostream>
#include <stdexcept>



int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		CTriangle triangle(2, 4, 3);
		std::cout << triangle.GetArea() << std::endl;
		std::cout << triangle.GetPerimeter() << std::endl;
	}
	catch (std::logic_error const & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	
	return 0;
}

