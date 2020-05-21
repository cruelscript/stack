#include <cmath>
#include "StackArray.h"
#include "Operator.h"

int charToInt(char symbol)
{
	return symbol & 0x0F;
}

char* transformToPostfix(const char* infix)
{
	char* postfix = new char[100];
	Stack<Operator>* stack = new StackArray<Operator>(100);

	char cText = '\0';
	int cCount = 0;	
	Operator current;

	for (int i = 0; (cText = infix[i]) != '\0'; i++)
	{
		if (cText >= '0' && cText <= '9')
		{
			postfix[cCount] = cText;
			cCount++;
		}
		else
		{
			current = Operator(cText);

			switch (current.getPriority()) 
			{
			case OPENING_BRACKET:
				stack->push(current);
				break;
			case CLOSING_BRACKET:
				stack->push(current);
				while (stack->pop().getPriority() != OPENING_BRACKET)
				{
					postfix[cCount] = stack->pop().sign();
					cCount++;
				}
				break;
			case PLUS_MINUS:
				while (stack->top().getPriority() >= PLUS_MINUS)
				{
					postfix[cCount] = stack->pop().sign();
					cCount++;
				}
				stack->push(current);
				break;
			case MUL_DIV:
				while (stack->top().getPriority() >= MUL_DIV)
				{
					postfix[cCount] = stack->pop().sign();
					cCount++;
				}
				stack->push(current);
				break;
			case POWER:
				stack->push(current);
				break;
			}
		}
	}
	while (!stack->isEmpty())
	{
		postfix[cCount] = stack->pop().sign();
		cCount++;
	}
	
	postfix[cCount] = '\0';
	delete stack;
	return postfix;
}

int calculate(const char* postfix)
{
	int result = 0;
	Stack<int>* stack = new StackArray<int>;
	char cText = '\0';

	int left = 0;
	int right = 0;

	for (int i = 0; (cText = postfix[i]) != '\0'; i++)
	{
		if (cText >= '0' && cText <= '9')
		{
			stack->push(charToInt(cText));
		}
		else
		{
			if (stack->isEmpty())
			{
				throw "Wrong postfix notation.";
			}

			left = stack->pop();
			right = stack->pop();	

			switch (cText)
			{
			
			case '+':
				right += left;
				break;
			case '-':
				right -= left;
				break;
			case '*':
				right *= left;
				break;
			case '/':
				if (left != 0)
					right /= left;
				else throw "Division by zero.";
				break;
			case '^':
				right = pow(right, left);
				break;
			}
			stack->push(right);
		}
	}
	result = stack->pop();
	delete stack;
	return result;
}