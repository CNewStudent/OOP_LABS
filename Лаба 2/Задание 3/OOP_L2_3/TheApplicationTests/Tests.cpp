#include "stdafx.h"
#include "../OOP_L2_3/Functions_L2_3.h"

BOOST_AUTO_TEST_CASE(Empty)
{
	string str;
	map<string, int> dict;
	
	str = "        ";
	dict = FillInDictionary(str);

	BOOST_CHECK(dict.size() == 0);
}

BOOST_AUTO_TEST_CASE(OneWord)
{
	string str, strResult;
	map<string, int> dict;

	
	str = "1234apple**@!";
	dict = FillInDictionary(str);
	map<string, int>::iterator it = dict.find("apple");
	BOOST_CHECK((*it).second == 1);
	BOOST_CHECK(dict.size() == 1);
}

BOOST_AUTO_TEST_CASE(FiveWords)
{
	string str, strResult;
	map<string, int> dict;


	str = "   apple!!!!apple   apple ***apple    apple   ";
	dict = FillInDictionary(str);
	map<string, int>::iterator it = dict.find("apple");
	BOOST_CHECK((*it).second == 5);
	BOOST_CHECK(dict.size() == 1);
}

BOOST_AUTO_TEST_CASE(DifferentWords)
{
	string str, strResult;
	map<string, int> dict;


	str = "  apple  apple juice juice ";
	dict = FillInDictionary(str);
	map<string, int>::iterator it = dict.find("apple");
	map<string, int>::iterator it_two = dict.find("juice");
	BOOST_REQUIRE((*it).second == 2);
	BOOST_REQUIRE((*it_two).second == 2);
	BOOST_CHECK(dict.size() == 2);
}

BOOST_AUTO_TEST_CASE(test)
{
	string str, strResult;
	map<string, int> dict;


	str = "111apple*$#!  11124&^";
	dict = FillInDictionary(str);
	BOOST_CHECK(dict.size() == 1);
}