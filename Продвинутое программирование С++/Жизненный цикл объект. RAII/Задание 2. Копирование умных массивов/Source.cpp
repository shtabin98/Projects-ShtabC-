#include <iostream>
#include <exception>

class smart_array
{
private:
	int size;
	int* array;
public:
	smart_array(int size_)
	{
		if (size_ < 0)
		{
			throw std::invalid_argument("размер не может быть отрицателен");
		}
		else
		{
			size = size_;
			array = new int[size] {};
		}
	}

	auto add_element(int elem_)
	{
		int* new_array = new int[size + 1] {};
		for (int i = 0; i < size; ++i)
		{
			new_array[i] = array[i];
		}
		new_array[size] = elem_;
		delete[] array;
		array = new_array;
		++size;
	}

	auto get_element(int n)
	{
		if (n >= 0 && n < size)
		{
			return array[n];
		}
		else
		{
			throw std::invalid_argument("введен некорректный индекс");
		}
	};
	
	smart_array& operator=(smart_array& other)
	{
		if (this == &other)
			return *this;
		delete[] array;

		size = other.size;
		array = (size == 0) ? nullptr : new int[size];
		for (int i = 0; i < size; ++i) {
			array[i] = other.array[i];
		}
		return *this;
	}

	~smart_array()
	{
		delete[] array;
	};
};

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}