#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int evaluatePrefix(const string& expr) {
    stack<int> stk;

    for (int i = expr.length() - 1; i >= 0; i--) {
        char ch = expr[i];

        if (ch == ' ') continue;

        if (isdigit(ch)) {
            int num = 0;
            int place = 1;

            while (i >= 0 && isdigit(expr[i])) {
                num = num + (expr[i] - '0') * place;
                place *= 10;
                i--;
            }
            i++;
            stk.push(num);
        }
        else {
            int operand1 = stk.top();
            stk.pop();
            int operand2 = stk.top();
            stk.pop();

            switch (ch) {
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

int main() {
    string expr;
    cout << "Enter a prefix expression: ";
    getline(cin, expr);

    int result = evaluatePrefix(expr);
    cout << "Result: " << result << endl;

    return 0;
}
