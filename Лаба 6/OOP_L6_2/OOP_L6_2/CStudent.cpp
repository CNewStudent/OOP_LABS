#include "stdafx.h"
#include "CStudent.h"
//#include <stdexcept>
#include "CTakhirException.h" 

/*
Не изменяемые внутри функции объекты следует либо передавать по константной ссылке
	либо по значению с последующей "кражей" содержимого
У класса строк есть метод empty()

*/

CStudent::CStudent(string const& name, string const& surname, 
	string const& patronymic, int const& age)
{
	if (name.size() == 0 || (count(name.begin(), name.end(), ' ') != 0))
	{
		throw CTakhirException("incorrect name is entered");
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
	m_patronymic  = patronymic;
	m_age = age;
}

CStudent::~CStudent()
{
}

string CStudent::GetName()
{
	return  m_name;
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