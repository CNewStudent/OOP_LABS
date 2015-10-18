#include "stdafx.h"
#include "CStudent.h"
#include <stdexcept>
#include "CTakhirException.h" 
#include <string>

/*
Не изменяемые внутри функции объекты следует либо передавать по константной ссылке
	либо по значению с последующей "кражей" содержимого
У класса строк есть метод empty()

*/
using namespace std;

CStudent::CStudent(const string & name, const string & surname,
	const string  & patronymic, int age)
{
	if (name.empty() || (count(name.begin(), name.end(), ' ') != 0))
	{
		throw CTakhirException("incorrect name is entered");
	}
	if (surname.empty() || (count(surname.begin(), surname.end(), ' ') != 0))
	{
		throw invalid_argument("incorrect surname is entered");
	}
	if (!patronymic.empty() && (count(patronymic.begin(), patronymic.end(), ' ') != 0))
	{
		throw invalid_argument("incorrect patronymic is entered");
	}
	if (age < 14 || age > 60)
	{
		throw out_of_range("incorrect age is entered");
	}
	m_name = name;
	m_surname = surname;
	m_patronymic  = patronymic;
	m_age = age;
}

CStudent::~CStudent()
{
}

string CStudent::GetName() const
{
	return  m_name;
}

string CStudent::GetSurname() const
{
	return m_surname;
}

string CStudent::GetPatronymic() const
{
	return m_patronymic;
}

int CStudent::GetAge() const
{
	return m_age;
}

void CStudent::Rename(string name, string surname, string patronymic)
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

	m_name.swap(name);
	m_surname.swap(surname);
	m_patronymic.swap(patronymic);

}

/*
При попытке помолодеть тип исключения должен быть другим
*/
void CStudent::SetAge(int age)
{
	if (age < 14 || age > 60)
	{
		throw out_of_range("incorrect age is entered");
	}

	if (m_age > age)
	{
		throw domain_error("incorrect age is entered");
	}
	
	m_age = age;
}