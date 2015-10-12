#include "stdafx.h"
#include"../OOP_L6_2/CStudent.h"
//#include "/Учеба/2 курс 2 семестр/OOP/Лаба 6/OOP_L6_2/TheApplicationTests/STakhirException.h"
#include <stdexcept>
#include "../OOP_L6_2/CTakhirException.h"

using namespace std;

void VerifyStudentState(const CStudent & student, const string & name, const string & surname, const string & patronymic, int age)
{
	BOOST_CHECK(student.GetName() == name);
	BOOST_CHECK(student.GetSurname() == surname);
	BOOST_CHECK(student.GetPatronymic() == patronymic);
	BOOST_CHECK(student.GetAge() == age);
}

BOOST_AUTO_TEST_CASE(Init)
{
	CStudent student("name", "surname", "patronymic", 20);
	BOOST_CHECK(student.GetName() == "name");
	BOOST_CHECK(student.GetSurname() == "surname");
	BOOST_CHECK(student.GetPatronymic() == "patronymic");
	BOOST_CHECK(student.GetAge() == 20);
}

BOOST_AUTO_TEST_CASE(InitWithoutPatronymic)
{
	CStudent student("name", "surname", "", 20);
	BOOST_CHECK(student.GetName() == "name");
	BOOST_CHECK(student.GetSurname() == "surname");
	BOOST_CHECK(student.GetPatronymic() == "");
	BOOST_CHECK(student.GetAge() == 20);
}

BOOST_AUTO_TEST_CASE(ChangeData)
{
	CStudent student("name", "surname", "patronymic", 20);
	student.Rename("noname", "nosurname", "");
	student.SetAge(60);
	BOOST_CHECK(student.GetName() == "noname");
	BOOST_CHECK(student.GetSurname() == "nosurname");
	BOOST_CHECK(student.GetPatronymic() == "");
	BOOST_CHECK(student.GetAge() == 60);
}

BOOST_AUTO_TEST_CASE(IncorrectName)
{
	BOOST_CHECK_THROW(CStudent student("na me", "surname", "patronymic", 20), CTakhirException);
}

BOOST_AUTO_TEST_CASE(IncorrectName2)
{
	BOOST_CHECK_THROW(CStudent student("", "surname", "patronymic", 20), CTakhirException);
}

BOOST_AUTO_TEST_CASE(IncorrectSurname)
{
	BOOST_CHECK_THROW(CStudent student("name", "sur name", "patronymic", 20), invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectSurname2)
{
	BOOST_CHECK_THROW(CStudent student("name", "", "patronymic", 20), invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectPatronymic)
{
	BOOST_CHECK_THROW(CStudent student("name", "surname", "patro nymic", 20), invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectAge)
{
	BOOST_CHECK_THROW(CStudent student("name", "surname", "patronymic", 13), out_of_range);
}

BOOST_AUTO_TEST_CASE(IncorrectChangeName)
{
		CStudent student("name", "surname", "patronymic", 55);
		BOOST_CHECK_THROW(student.Rename("no name", "nosurname", "nopatronymic"), invalid_argument)
}

BOOST_AUTO_TEST_CASE(IncorrectChangeName2)
{
	CStudent student("name", "surname", "patronymic", 55);
	BOOST_CHECK_THROW(student.Rename("", "nosurname", "nopatronymic"), invalid_argument)
}

BOOST_AUTO_TEST_CASE(IncorrectChangeSurname)
{
	CStudent student("name", "surname", "patronymic", 55);
	BOOST_CHECK_THROW(student.Rename("noname", "no surname", "nopatronymic"), invalid_argument)
}

BOOST_AUTO_TEST_CASE(IncorrectChangeSurname2)
{
	CStudent student("name", "surname", "patronymic", 55);
	BOOST_CHECK_THROW(student.Rename("noname", "", "nopatronymic"), invalid_argument)
}

BOOST_AUTO_TEST_CASE(IncorrectChangePatronymic)
{
	CStudent student("name", "surname", "patronymic", 55);
	BOOST_CHECK_THROW(student.Rename("noname", "nosurname", "no patronymic"), invalid_argument)
}


BOOST_AUTO_TEST_CASE(IncorrectChangeAge)
{
	CStudent student("name", "surname", "patronymic", 55);
	BOOST_CHECK_THROW(student.SetAge(45), domain_error);
}

BOOST_AUTO_TEST_CASE(IncorrectChangeAge2)
{
	CStudent student("name", "surname", "patronymic", 55);
	BOOST_CHECK_THROW(student.SetAge(75), out_of_range);
}