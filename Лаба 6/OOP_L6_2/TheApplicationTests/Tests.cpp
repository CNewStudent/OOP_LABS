#include "stdafx.h"
#include"../OOP_L6_2/CStudent.h"
#include <stdexcept>

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
	try
	{
		CStudent student("na me", "surname", "patronymic", 20);
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(IncorrectName2)
{
	try
	{
		CStudent student("", "surname", "patronymic", 20);
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(IncorrectSurname)
{
	try
	{
		CStudent student("name", "sur name", "patronymic", 20);
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(IncorrectSurname2)
{
	try
	{
		CStudent student("name", "", "patronymic", 20);
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(IncorrectPatronymic)
{
	try
	{
		CStudent student("name", "surname", "patro nymic", 20);
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(IncorrectAge)
{
	try
	{
		CStudent student("name", "surname", "patronymic", 61);
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(IncorrectChangeName)
{
	try
	{
		CStudent student("name", "surname", "patronymic", 55);
		student.Rename("no name", "nosurname", "nopatronymic");
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(IncorrectChangeName2)
{
	try
	{
		CStudent student("name", "surname", "patronymic", 55);
		student.Rename("", "nosurname", "nopatronymic");
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(IncorrectChangeSurname)
{
	try
	{
		CStudent student("name", "surname", "patronymic", 55);
		student.Rename("noname", "nosur name", "nopatronymic");
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(IncorrectChangeSurname2)
{
	try
	{
		CStudent student("name", "surname", "patronymic", 55);
		student.Rename("noname", "", "nopatronymic");
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(IncorrectChangePatronymic)
{
	try
	{
		CStudent student("name", "surname", "patronymic", 55);
		student.Rename("noname", "nosurname", "nopa tronymic");
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}

BOOST_AUTO_TEST_CASE(CorrectChangePatronymic)
{
	try
	{
		CStudent student("name", "surname", "patronymic", 55);
		student.Rename("noname", "nosurname", "");
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(!e.what());
	}
}

BOOST_AUTO_TEST_CASE(IncorrectChangeAge)
{
	try
	{
		CStudent student("name", "surname", "patronymic", 55);
		student.SetAge(40);
	}
	catch (logic_error const & e)
	{
		BOOST_CHECK(e.what());
	}
}