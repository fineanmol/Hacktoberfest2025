// parentheses_checker.cpp
// Compile with: g++ -std=c++17 parentheses_checker.cpp -o parentheses_checker

#include <bits/stdc++.h>
using namespace std;

// Check if a pair of brackets match
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Check if the string has balanced parentheses/brackets/braces
bool areParenthesesBalanced(const string &s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty() || !isMatching(st.top(), ch)) {
                return false; // unmatched closing
            }
            st.pop();
        }
    }
    return st.empty(); // balanced iff nothing left unmatched
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter strings to check (Ctrl+D/Ctrl+Z to end):\n";
    string line;

    // Read multiple lines until EOF
    while (getline(cin, line)) {
        if (line.empty()) continue; // skip empty lines
        bool balanced = areParenthesesBalanced(line);
        cout << line << " -> " << (balanced ? "Balanced" : "Not Balanced") << '\n';
    }

    return 0;
}
