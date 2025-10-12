#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to return precedence of operators
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";

    for(char c : infix) {
        if(c == ' ' || c == ',') continue;  // ignore spaces and commas

        if(isalpha(c) || isdigit(c)) {
            // Operand, add to postfix
            postfix += c;
            postfix += ' '; // separator for clarity
        }
        else if(c == '(') {
            s.push(c);
        }
        else if(c == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            if(!s.empty()) s.pop(); // remove '('
        }
        else if(isOperator(c)) {
            while(!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators from stack
    while(!s.empty()) {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    return postfix;
}

int main() {
    string infixExpr;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpr);

    string postfixExpr = infixToPostfix(infixExpr);

    cout << "Postfix Expression: " << postfixExpr << endl;

    return 0;
}
