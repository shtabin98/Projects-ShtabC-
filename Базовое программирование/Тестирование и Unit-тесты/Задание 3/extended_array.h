#pragma once
#include <utility>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
class ExtArray
{
private:
	std::vector<T> extended_array;
	size_t _size;
public:
	ExtArray(std::initializer_list<T> l) : extended_array(l)
	{
		_size = l.size();
	}

	ExtArray(int size) : _size(size)
	{
		extended_array.resize(_size);
	}

	T& operator[](size_t index)
	{
		return extended_array[index];
	}

	size_t size()
	{
		return _size;
	}

	double mean()
	{
		if (_size == 0)
		{
			return 0;
		}
		double sum = 0;
		for (size_t i = 0; i < _size; i++)
		{
			sum += extended_array[i];
		}
		return sum / _size;
	}

	double mean(size_t begin, size_t end)
	{
		if (_size == 0)
		{
			return 0;
		}
		if (begin >= end)
		{
			throw std::invalid_argument("Начальный номер диапазона большше, либо равен конечному");
		}

		double sum = 0;
		size_t count = end - begin;

		for (size_t i = begin; i < end; i++)
		{
			sum += extended_array[i];
		}
		return sum / count;
	}

	double median()
	{
		if (_size == 0)
		{
			return 0;
		}
		std::vector<T> temp_array;
		std::copy(extended_array.begin(), extended_array.end(), back_inserter(temp_array));
		std::sort(temp_array.begin(), temp_array.end());
		if (_size % 2 == 1)
		{
			return temp_array[_size / 2];
		}
		else
		{
			return static_cast<double>(temp_array[(_size / 2) - 1] + temp_array[_size / 2]) / 2;
		}
	}

	std::pair<T, int> mode()
	{
		if (_size == 0)
		{
			return std::make_pair(T{},0);
		}
		T max = extended_array[0], cmax = 0, rmax = 0;
		for (int i = 0; i < _size; i++)
		{
			if (cmax > rmax)
			{
				rmax = cmax;
				max = extended_array[i - 1];
			}
			cmax = 0;
			for (int j = i; j < _size; j++)
			{
				if (extended_array[j] == extended_array[i])
				{
					cmax++;
				}
			}
		}
		return std::pair<T, int>(max, rmax);
	}

	int checkSum()
	{
		if (!std::is_same_v<T, bool> && !std::is_same_v<T, int>)
		{
			throw std::bad_typeid();
		}

		int count{ 0 };

		if (std::is_same_v<T, int>)
		{
			for (int i = 0; i < _size; i++)
			{
				if (extended_array[i] != 0 && extended_array[i] != 1)
				{
					throw std::logic_error("Значения целочисленного массива не 0 или 1");
				}
				else
				{
					if (extended_array[i] == 1)
					{
						count++;
					}
				}
			}
		}

		if (std::is_same_v<T, bool>)
		{
			for (int i = 0; i < _size; i++)
			{
				if (extended_array[i] == true)
				{
					count++;
				}
			}
		}
		return count;
	}
};
