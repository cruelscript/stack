#include "StackList.h"
#include "StackArray.h"

bool testBalanceBrackets(const char* text, bool isList, int maxDepth)
{
	Stack<char>* stack;

	if (isList)
		stack = new StackList<char>;
	else stack = new StackArray<char>(maxDepth);


	bool isBalanceBrackets = true;

	try
	{
		char cText = '\0';

		for (int i = 0;
			((cText = text[i]) != '\0') && (isBalanceBrackets == true);
			i++)
		{
			switch (cText)
			{
			case '(': case '[': case '{':
				stack->push(cText);
				break;
			case ')':
				if (stack->pop() != '(')
					isBalanceBrackets = false;
				break;
			case ']':
				if (stack->pop() != '[')
					isBalanceBrackets = false;
				break;
			case '}':
				if (stack->pop() != '{')
					isBalanceBrackets = false;
				break;
			}
		}

		isBalanceBrackets = isBalanceBrackets && stack->isEmpty();
	}
	catch (StackUnderflow)
	{
		isBalanceBrackets = false;
	}
	catch (StackOverflow)
	{
		isBalanceBrackets = false;
	}

	delete stack;

	return isBalanceBrackets;
}

int calculateDepth(const char* text)
{
	Stack<char>* stack = new StackList<char>;

	bool isBalanceBrackets = true;
	int nOpenBrackets = 0;
	int nClosedBrackets = 0;

	try {

		char cText = '\0';

		for (int i = 0;
			((cText = text[i]) != '\0') && isBalanceBrackets;
			i++)
		{
			switch (cText)
			{
			case '(': case '[': case '{':
				stack->push(cText);
				nOpenBrackets++;
				if (nClosedBrackets != 0)
				{
					nOpenBrackets--;
					nClosedBrackets = 0;
				}


				break;
			case ')':
				if (stack->pop() != '(')
					isBalanceBrackets = false;
				nClosedBrackets++;
				break;
			case ']':
				if (stack->pop() != '[')
					isBalanceBrackets = false;
				nClosedBrackets++;
				break;
			case '}':
				if (stack->pop() != '{')
					isBalanceBrackets = false;
				nClosedBrackets++;
				break;
			}
		}

		isBalanceBrackets = isBalanceBrackets && stack->isEmpty();
	}
	catch (StackUnderflow)
	{
		isBalanceBrackets = false;
	}
	catch (StackOverflow)
	{
		isBalanceBrackets = false;
	}

	if (!isBalanceBrackets)
		return -1;
	else return nOpenBrackets;
}