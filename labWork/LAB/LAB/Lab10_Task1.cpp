/*#include <stack>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string expression;
    stack<double> nameOfStack;
    cout << "Type in a postFix express or stop to stop" << endl;
    cin >> expression;
    while (strcmp(expression.c_str(), "stop") != 0) {               // Not != to stop keep running the program
        if (strcmp(expression.c_str(), "+") == 0) {
            double n1 = nameOfStack.top();
            nameOfStack.pop();
            double n2 = nameOfStack.top();
            nameOfStack.pop();
            nameOfStack.push(n1 + n2);                              //if the string is +, pop the last 2 values from the stack and push back their sum

        } else if (strcmp(expression.c_str(), "*") == 0) {
            double n1 = nameOfStack.top();
            nameOfStack.pop();
            double n2 = nameOfStack.top();
            nameOfStack.pop();
            nameOfStack.push(n1 * n2);                              //else  if the string is *,pop the last 2 values from the stack and push back their product

        } else if (strcmp(expression.c_str(), "-") == 0) {
            double n1 = nameOfStack.top();
            nameOfStack.pop();
            double n2 = nameOfStack.top();
            nameOfStack.pop();
            nameOfStack.push(n2 - n1);                              //else if the string is -, pop the last 2 values from the stack and push back the second –  the first

        } else if (strcmp(expression.c_str(), "/") == 0) {
            double n1 = nameOfStack.top();
            nameOfStack.pop();
            double n2 = nameOfStack.top();
            nameOfStack.pop();
            nameOfStack.push(n2 / n1);                              // else if the string is /, pop the last 2 values from the stack and push back the second /  the first
        } else if (strcmp(expression.c_str(), "=") == 0) {
            double result = nameOfStack.top();
            nameOfStack.pop();
            cout << fixed << showpoint << setprecision(5) << result << endl;
        } else {
            nameOfStack.push(atof(expression.c_str()));
        }
        cin >> expression;
    }
    return 0;
}*/