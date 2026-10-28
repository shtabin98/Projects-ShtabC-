#ifndef TIPO_VECTOR
#define TIPO_VECTOR

#include <stdexcept>
#include <cstddef>

template <typename T>
class tipo_vector
{
	T* data;
	size_t _size;
	size_t _capacity;
public:
	tipo_vector() : data(nullptr), _size(0), _capacity(0) {}

	~tipo_vector()
	{
		delete[] data;
	}

	T& at(size_t index)
	{
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}

	void push_back(T value)
	{
		if (_size == _capacity) {
			size_t new_capacity = _capacity == 0 ? 1 : _capacity * 2;
			T* new_data = new T[new_capacity];

			for (size_t i = 0; i < _size; ++i) {
				new_data[i] = data[i];
			}

			delete[] data;
			data = new_data;
			_capacity = new_capacity;
		}

		data[_size] = value;
		++_size;
	}

	size_t size() const { return _size; }

	size_t capacity() const { return _capacity; }
};

#endif