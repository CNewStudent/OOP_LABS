#pragma once
#include <stdexcept>
#include <algorithm>
#include <cstdlib>

using namespace std;

template <class T>
class CMyArray {
public:
	CMyArray() :m_size(0)
	{
		m_data = new T[1];
	};

	CMyArray(CMyArray & other)
	{
		delete[] m_data;
		m_data = new T[other.Size()];
		for (int i = 0; i < other.Size(); i++)
		{
			m_data[i] = other[i];
		}
		m_size = other.Size();
	};

	void Add(T element)
	{
		T * assistArray = new T[m_size + 1];
		for (size_t i = 0; i < m_size; i++)
		{
			assistArray[i] = m_data[i];
		}
		delete[]m_data;
		m_data = new T[m_size + 1];

		m_data = assistArray;
		/*for (size_t i = 0; i < m_size + 1; i++)
		{
			m_data[i] = assistArray[i];
		}*/

		m_data[m_size] = element;
		m_size++;
	};

	int Size()
	{
		return m_size;
	}

	T & operator [](size_t index)
	{
		if ((index >= 0) && (index < m_size) && (m_size != 0))
		{
			return m_data[index];
		}
		throw std::out_of_range("Выход за границы массива");
	}

	CMyArray & operator = (const CMyArray & other)
	{
		delete[] m_data;
		m_size = other.Size();
		m_data = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = other[i];
		}
	}

	void Resize(size_t size)
	{
		T * assistArray = new  T[size];
		for (size_t i = 0; i < std::min(m_size, size); i++)
		{
			assistArray[i] = m_data[i];
		}
		delete[] m_data;
		m_data = assistArray;

		T element = T();
		for (size_t i = m_size; i < size; i++)
		{
			m_data[i] = element;
		}
		m_size = size;
	};

	void Clear()
	{
		m_size = 0;
		delete[] m_data;
	};

	~CMyArray()
	{
		if (m_size != 0)
		{
			delete[] m_data;
		}
	};

private:
	size_t m_size;
	T * m_data;
};