#include <iostream>
#include <cctype>
using namespace std;

char stack[100];
int top = -1;

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    string exp, postfix = "";

    cout << "Enter infix expression: ";
    getline(cin, exp);

    for (char c : exp) {
        if (c == ' ')
            continue;

        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix += stack[top--];

            top--;
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(c))
                postfix += stack[top--];

            stack[++top] = c;
        }
    }

    while (top != -1)
        postfix += stack[top--];

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
