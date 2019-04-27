#ifndef STACK_H_
#define STACK_H_
#include <fstream>
#include <iostream>
#include <iomanip>

template <typename T>
class Stack
{
private:
	T* arr;
	size_t capacity;
	size_t size;
private:
	void resize();
public:
	Stack(size_t newCapacity);
	Stack(std::ifstream& ifs);
	
	void add(const T& element);
	bool pop();
	T peek();
	bool isEmpty() const;
	void print() const;
	void writeInFile(const char* fileName) const;
	void sorting();
};

template <typename T>
Stack<T>::Stack(size_t newCapacity) :capacity(newCapacity), size(0)
{
	arr = new (std::nothrow) T[capacity];
}


template <typename T>
Stack<T>::Stack(std::ifstream& ifs)
{
	unsigned int count = 0;
	unsigned int i = 0;
	T buff;
	while (!ifs.eof())
	{
		ifs >> buff;
		count++;
	}
	arr = new T[count];
	while (!ifs.eof())
	{
		ifs >> arr[i];
		i++;
	}
}

template <typename T>
void Stack<T>::resize()
{
	T* buff;
	buff = arr;
	arr = new T[capacity * 2];
	for (size_t i = 0; i < size; ++i)
	{
		arr[i] = buff[i];
	}
	capacity *= 2;
	delete[] buff;
}


template <typename T>
void Stack<T>::add(const T& element)
{
	if (size == capacity)
	{
		resize();
	}
	arr[size] = element;
	size++;
}

template <typename T>
bool Stack<T>::pop()
{
	if (!size)
	{
		return false;
	}
	size--;
	return true;
}

template<typename T>
T Stack<T>::peek()
{
	return arr[size - 1];
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return !size;
}

template <typename T>
void Stack<T>::print() const
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void Stack<T>::writeInFile(const char * fileName) const
{
	std::ofstream ofs(fileName);
	if (ofs.is_open())
	{
		for (size_t i = 0; i < size; ++i)
		{
			if ((i % 3) == 0 && (i!= 0))
			{
				ofs << std::endl;
			}
			ofs << arr[i] << ' ';		
		}
		std::cout << std::endl;
	}
	ofs.close();
}

template<typename T>
void Stack<T>::sorting()
{
	Stack<T> tmpStack(size);
	while (!isEmpty())
	{
		T tmp = peek();
		pop();
		while (!tmpStack.isEmpty() && tmpStack.peek() > tmp)
		{
			add(tmpStack.peek());
			tmpStack.pop();
		}
		tmpStack.add(tmp);
	}
	*this = tmpStack;
}

template <>
void Stack<double>::print() const
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::setprecision(5) << arr[i] << ' ';
	}
	std::cout << std::endl;
}

template <>
void Stack<char>::print() const
{
	char temp = 'a' - 'A';
	for (size_t i = 0; i < size; ++i)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			std::cout << arr[i] - temp << ' ';
		}
		else
		{
			std::cout << arr[i] << ' ';
		}
	}
	std::cout << std::endl;
}

#endif
