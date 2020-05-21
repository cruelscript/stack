#include <iostream>
#include <iomanip>
#include "Operator.h"
#include "StackArray.h"

using namespace std;

bool testBalanceBrackets(const char* text, bool isList = true, int maxDepth = 30);
int calculateDepth(const char* text);
char* transformToPostfix(const char* infix);
int calculate(const char* postfix);

int main()
{
    const char* text00 = " ok ";
    cout << text00 << ": " << (testBalanceBrackets(text00) ? "right" : "wrong") << endl;
    const char* text01 = "( ) ok ";
    cout << text01 << ": " << (testBalanceBrackets(text01) ? "right" : "wrong") << endl;
    const char* text02 = "( ( [] ) ) ok ";
    cout << text02 << ": " << (testBalanceBrackets(text02) ? "right" : "wrong") << endl;
    const char* text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
    cout << text03 << ": " << (testBalanceBrackets(text03) ? "right" : "wrong") << endl;
    const char* text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
    cout << text04 << ": " << (testBalanceBrackets(text04) ? "right" : "wrong") << endl;
    const char* text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
    cout << text05 << ": " << (testBalanceBrackets(text05) ? "right" : "wrong") << endl;
    const char* text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
    cout << text06 << ": " << (testBalanceBrackets(text06) ? "right" : "wrong") << endl;

	  cout << text00 << ": " << calculateDepth(text00)  << endl;
	  cout << text01 << ": " << calculateDepth(text01) << endl;
	  cout << text02 << ": " << calculateDepth(text02) << endl;
	  cout << text03 << ": " << calculateDepth(text03) << endl;
	  cout << text04 << ": " << calculateDepth(text04) << endl;
	  cout << text05 << ": " << calculateDepth(text05) << endl;
	  cout << text06 << ": " << calculateDepth(text06) << endl;
    
    cout << endl;

    const char* text07 = "(4*(6-3))+((8-6)/2)";
    const char* text08 = "(2+4)*(3+7)-1";
    const char* text09 = "4*(5-3)";
    const char* text10 = "2+2*2";
    const char* text11 = "1-2+5";


    const char* no = "4r";
    try
    {

        cout << setw(20) << text07 << " [=] " << setw(12) << transformToPostfix(text07) << " [=] " << calculate(transformToPostfix(text07)) << endl;
        cout << setw(20) << text08 << " [=] " << setw(12) << transformToPostfix(text08) << " [=] " << calculate(transformToPostfix(text08)) << endl;
        cout << setw(20) << text09 << " [=] " << setw(12) << transformToPostfix(text09) << " [=] " << calculate(transformToPostfix(text09)) << endl;
        cout << setw(20) << text10 << " [=] " << setw(12) << transformToPostfix(text10) << " [=] " << calculate(transformToPostfix(text10)) << endl;
        cout << setw(20) << text11 << " [=] " << setw(12) << transformToPostfix(text11) << " [=] " << calculate(transformToPostfix(text11)) << endl;

        //invalid operand
        cout << setw(20) << no << " [=] " << setw(12) << transformToPostfix(no) << " [=] " << calculate(transformToPostfix(no)) << endl;

        StackArray<int> stack;
        stack.push(3);
        stack.push(4);
        cout << stack.pop() << endl << stack.pop() << endl;
        cout << stack.isEmpty() << endl;

    }
    catch (WrongOperator exception)
    {
        std::cout << exception.what();
    }
    return 0;
}
