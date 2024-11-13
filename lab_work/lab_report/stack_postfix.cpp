#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int evaluatePostfix(const string &expr)
{
    stack<int> stk;

    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];

        if (ch == ' ')
            continue;

        if (isdigit(ch))
        {
            int num = 0;
            while (i < expr.length() && isdigit(expr[i]))
            {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            stk.push(num);
        }
        else
        {
            int operand2 = stk.top();
            stk.pop();
            int operand1 = stk.top();
            stk.pop();

            switch (ch)
            {
            case '+':
                stk.push(operand1 + operand2);
                break;
            case '-':
                stk.push(operand1 - operand2);
                break;
            case '*':
                stk.push(operand1 * operand2);
                break;
            case '/':
                stk.push(operand1 / operand2);
                break;
            case '^':
                stk.push(pow(operand1, operand2));
                break;
            default:
                cout << "Unsupported operator: " << ch << endl;
                return -1;
            }
        }
    }
    return stk.top();
}

int main()
{
    string expr;
    cout << "Enter a postfix expression: ";
    getline(cin, expr);

    int result = evaluatePostfix(expr);
    cout << "Result: " << result << endl;

    return 0;
}
