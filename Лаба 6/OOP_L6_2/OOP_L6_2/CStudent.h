#pragma once
#include <string>

using namespace std;

class CStudent
{
public:
	CStudent(string const& name, string const& surname, 
		string const& patronymic, int const& age);
	~CStudent();
	string GetName();
	string GetSurname();
	string GetPatronymic();
	int GetAge();
	void Rename(string name, string surname, string patronymic);
	void SetAge(int age);
private:
	int m_age;
	string m_name, m_surname, m_patronymic;
};

