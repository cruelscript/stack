#ifndef STACK_OPERATOR_H
#define STACK_OPERATOR_H

#include <exception>
#include "operators.h"

class Operator
{
public:
	Operator() = default;
	~Operator() = default;
	Operator(char symbol);
	const char sign() { return sign_; }
	const int getPriority() { return priority_; }
private:
	
	char sign_ = '\0';
	int priority_ = -1;
};


class WrongOperator : public std::exception
{
public:
	WrongOperator() : reason("Wrong Operator") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

#endif // !STACK_OPERATOR_H

