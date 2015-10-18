#pragma once
#include <string>


class CStudent
{
public:
	CStudent(const std::string & name, const std::string & surname,
		const std::string & patronymic, int age);
	~CStudent();
	std::string GetName() const;
	std::string GetSurname() const;
	std::string GetPatronymic() const;
	int GetAge() const;
	void Rename(std::string name, std::string surname, std::string patronymic);
	void SetAge(int age);
private:
	int m_age;
	std::string m_name, m_surname, m_patronymic;
};

