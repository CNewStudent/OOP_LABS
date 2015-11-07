// OOP_L4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Classes.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>


using namespace std;


double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

vector<string> SplitString(string line, string const& separator)
{
	vector<string> result;

	line += separator;
	string str = "";
	size_t i = 0;
	while (i < line.size())
	{
		if (separator == line.substr(i, separator.size()))
		{
			if (str != "")
			{
				result.push_back(str);
			}
			str = "";
			i += separator.size();
		}
		else
		{
			str += line[i];
			i++;
		}
	}
	return result;
}

vector<double> GetArrayDoubleFromArrayString(vector<string> array, bool & err)
{
	vector<double> result;

	for (size_t i = 0; i < array.size(); i++)
	{
		auto value = StringToDouble(array[i].c_str(), err);

		if (err)
		{
			break;
		}

		result.push_back(value);
	}

	return result;
}

shared_ptr<IShape> CreatePoint(bool err, string const & line, int sizeLine)
{
	auto values = GetArrayDoubleFromArrayString(SplitString(line.substr(sizeLine), " "), err);

	if (values.size() == 2 && !err)
	{
		err = true;
		shared_ptr<IShape> ptr = shared_ptr<CPoint>(new CPoint(values[0], values[1]));
		return ptr;
	}
	else
	{
		cout << "For example: Point x y" << endl;
		err = false;
	}
	return nullptr;
}

shared_ptr<IShape> CreateLineSigment(bool err, string const & line, int sizeLine)
{
	auto values = GetArrayDoubleFromArrayString(SplitString(line.substr(sizeLine), " "), err);
	if (values.size() == 4 && !err)
	{
		err = true;
		shared_ptr<IShape> ptr = shared_ptr<CLineSegment>(new CLineSegment(values[0], values[1], values[2], values[3]));
		return ptr;
	}
	else
	{
		cout << "For example: LineSigment x1 y1 x2 y2" << endl;
		err = false;
	}
	return nullptr;
}

shared_ptr<IShape> CreateRectangle(bool err, string const & line, int sizeLine)
{
	auto values = GetArrayDoubleFromArrayString(SplitString(line.substr(sizeLine), " "), err);
	if (values.size() == 4 && !err)
	{
		err = true;
		shared_ptr<IShape> ptr = shared_ptr<CRectangle>(new CRectangle(values[0], values[1], values[2], values[3]));
		return ptr;
	}
	else
	{
		cout << "For example: Rectangle x y length width" << endl;
		err = false;
	}
	return nullptr;
}

shared_ptr<IShape> CreateTriangle(bool err, string const & line, int sizeLine)
{
	auto values = GetArrayDoubleFromArrayString(SplitString(line.substr(sizeLine), " "), err);
	if (values.size() == 6 && !err)
	{
		err = true;
		shared_ptr<IShape> ptr = shared_ptr<CTriangle>(new CTriangle(values[0], values[1], values[2], values[3], values[4], values[5]));
		return ptr;
	}
	else
	{
		cout << "For example: Triangle x1 y1 x2 y2 x3 y3" << endl;
		err = false;
	}
	return nullptr;
}

shared_ptr<IShape> CreateCircle(bool err, string const & line, int sizeLine)
{
	auto values = GetArrayDoubleFromArrayString(SplitString(line.substr(sizeLine), " "), err);
	if (values.size() == 3 && !err)
	{
		err = true;
		shared_ptr<IShape> ptr = shared_ptr<CCircle>(new CCircle(values[0], values[1], values[2]));
		return ptr;
	}
	else
	{
		cout << "For example: Circle x y radius" << endl;
		err = false;
	}
	return nullptr;
}

void ApplyOperation(vector<shared_ptr<IShape>> & arrayPtr, string const & line)
{
	const string point = "Point";
	const string lineSigment = "LineSigment";
	const string rectangle = "Rectangle";
	const string triangle = "Triangle";
	const string circle = "Circle";

	bool err = false;

	if (line.substr(0, point.size()) == point)
	{
		arrayPtr.push_back(CreatePoint(err, line, point.size()));
	}
	else if (line.substr(0, lineSigment.size()) == lineSigment)
	{
		arrayPtr.push_back(CreateLineSigment(err, line, lineSigment.size()));
	}
	else if (line.substr(0, rectangle.size()) == rectangle)
	{
		arrayPtr.push_back(CreateRectangle(err, line, rectangle.size()));
	}
	else if (line.substr(0, triangle.size()) == triangle)
	{
		arrayPtr.push_back(CreateTriangle(err, line, triangle.size()));
	}
	else if (line.substr(0, circle.size()) == circle)
	{
		arrayPtr.push_back(CreateCircle(err, line, circle.size()));
	}
	else
	{
		cout << "Does not recognize the command." << endl;
		err = false;
	}
	
}


void AddShapes(istream & input, vector<shared_ptr<IShape>> & shapes)
{
	std::string line;

	while (getline(input, line))
	{
		ApplyOperation(shapes, line);
	}
}


void SortPerimetr(vector<shared_ptr<IShape>> & array)
{
	sort(array.begin(), array.end(), [](shared_ptr<IShape> const & first, shared_ptr<IShape> const & second)
	{
		return (first->GetPerimetr() > second->GetPerimetr());
	});
}

void SortArea(vector<shared_ptr<IShape>> & array)
{
	sort(array.begin(), array.end(), [](shared_ptr<IShape> const & first, shared_ptr<IShape> const & second)
	{
		return (first->GetArea() < second->GetArea());
	});

}

void PrintShapeInfo(vector<shared_ptr<IShape>> const & array)
{
	for (size_t j = 0; j < array.size(); j++)
	{
		cout << array[j]->ToString() << " " << "Area: " << array[j]->GetArea()
			<< " " << "Perimetr: " << array[j]->GetPerimetr() << endl;
	}

}

void Show(vector<shared_ptr<IShape>> & array)
{
	if (array.size() != 0)
	{
		SortArea(array);
		PrintShapeInfo(array);

		cout << "========================" << endl;

		SortPerimetr(array);
		PrintShapeInfo(array);
	}
}



int main(int argc, char* argv[])
{
	vector<shared_ptr<IShape>> shapes;

	AddShapes(std::cin, shapes);
	Show(shapes);
	
	return 0;
}