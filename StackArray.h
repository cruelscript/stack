#ifndef STACK_STACKARRAY_H
#define STACK_STACKARRAY_H

#include "Stack.h"

template <class T>
class StackArray : public Stack<T>
{
public:
	StackArray(int size = 100);
	StackArray(const StackArray<T>& src);
	virtual ~StackArray() { delete[] array_; }
	void push(const T& e);
	 T& pop();
	 T& top() { return array_[top_]; }
	bool isEmpty() { return top_ == 0; }
private:
	T* array_;
	int top_ = 0;
	int size_;
};

template <class T>
StackArray<T>::StackArray(int size)
{
	try
	{
		array_ = new T[size_ = size];
	}
	catch (...)
	{
		throw WrongStackSize();
	}
	top_ = 0;
}

template <class T>
StackArray<T>::StackArray(const StackArray<T>& src)
{
	try
	{
		array_ = new T[size_ = src.size_];
	}
	catch (...)
	{
		throw WrongStackSize();
	}
	for (int i = 0; i < src.top_; i++)
		array_[i] = src.array_[i];
	top_ = src.top_;
}

template <class T>
void StackArray<T>::push(const T& e)
{
	if (top_ == size_)
		throw StackOverflow();
	top_++;
	array_[top_] = e;
}

template <class T>
 T& StackArray<T>::pop()
{
	if (top_ == 0)
		throw StackUnderflow();
	return array_[top_--];
}

#endif //!STACK_STACKARRAY_H