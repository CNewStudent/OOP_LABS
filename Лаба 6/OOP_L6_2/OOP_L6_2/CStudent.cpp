#include "stdafx.h"
#include "CStudent.h"
#include <stdexcept>


CStudent::CStudent(string name, string surname, string patronymic, int age)
{
	if (name.size() == 0 || (count(name.begin(), name.end(), ' ') != 0))
	{
		throw invalid_argument("incorrect name is entered");
	}
	if (surname.size() == 0 || (count(surname.begin(), surname.end(), ' ') != 0))
	{
		throw invalid_argument("incorrect surname is entered");
	}
	if (patronymic.size() != 0 && (count(patronymic.begin(), patronymic.end(), ' ') != 0))
	{
		throw invalid_argument("incorrect patronymic is entered");
	}
	if (age < 14 || age > 60)
	{
		throw out_of_range("incorrect age is entered");
	}
	m_name = name;
	m_surname = surname;
	m_patronymic = patronymic;
	m_age = age;
}

CStudent::~CStudent()
{
}

string CStudent::GetName()
{
	return m_name;
}

string CStudent::GetSurname()
{
	return m_surname;
}

string CStudent::GetPatronymic()
{
	return m_patronymic;
}

int CStudent::GetAge()
{
	return m_age;
}

void CStudent::Rename(string name, string surname, string patronymic)
{
	if (name.size() == 0 || (count(name.begin(), name.end(), ' ') != 0))
	{
		throw invalid_argument("incorrect name is entered");
	}
	else
	{
		m_name.clear();
		m_name = name;
	}
	if (surname.size() == 0 || (count(surname.begin(), surname.end(), ' ') != 0))
	{
		throw invalid_argument("incorrect surname is entered");
	}
	else
	{
		m_surname.clear();
		m_surname = surname;
	}
	if (patronymic.size() != 0 && (count(patronymic.begin(), patronymic.end(), ' ') != 0))
	{
		throw invalid_argument("incorrect patronymic is entered");
	}
	else
	{
		m_patronymic.clear();
		m_patronymic = patronymic;
	}
}

void CStudent::SetAge(int age)
{
	if (age < 14 || age > 60 || age < m_age)
	{
		throw out_of_range("incorrect age is entered");
	}
	
	m_age = age;
}