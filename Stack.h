#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <exception>

template <class T>
class Stack
{
public:
	virtual ~Stack() {};
	virtual void	push(const T& e) = 0;
	virtual T&		pop()						 = 0;
	virtual T&		top()						 = 0;
	virtual bool	isEmpty()				 = 0;
};

class StackOverflow : public std::exception
{
public:
	StackOverflow() : reason("Stack Overflow") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

class StackUnderflow : public std::exception
{
public:
	StackUnderflow() : reason("Stack Underflow") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : reason("Wrong Stack Size") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

#endif // !STACK_STACK_H
