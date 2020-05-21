#include "Operator.h"

Operator::Operator(char symbol)
{
	switch (symbol)
	{
	case '(':
		priority_ = OPENING_BRACKET;
		break;
	case ')':
		priority_ = CLOSING_BRACKET;
		break;
	case '-':
	case '+':
		priority_ = PLUS_MINUS;
		break;
	case '/':
	case '*':
		priority_ = MUL_DIV;
		break;
	case '^':
		priority_ = POWER;
		break;
	default: throw WrongOperator();
	}
	sign_ = symbol;
}