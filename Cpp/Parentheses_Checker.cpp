// parentheses_checker.cpp
// Compile with: g++ -std=c++17 parentheses_checker.cpp -o parentheses_checker

#include <bits/stdc++.h>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')')
        || (open == '[' && close == ']')
        || (open == '{' && close == '}');
}

bool areParenthesesBalanced(const string &s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty() || !isMatching(st.top(), ch)) {
                return false; // closing bracket without matching opening
            }
            st.pop();
        }
        // ignore other characters
    }
    return st.empty(); // balanced iff nothing left unmatched
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter string to check (single line). Press Ctrl+D/Ctrl+Z to end:\n";
    string line;
    // Read whole line (including spaces). For multiple tests, loop or read until EOF.
    if (!getline(cin, line)) return 0;

    bool balanced = areParenthesesBalanced(line);
    if (balanced) cout << "Balanced\n";
    else cout << "Not Balanced\n";

    // Example quick tests (uncomment to run built-in tests)
    /*
    vector<string> tests = {
        "()[]{}", "([{}])", "(]", "([)]", "a + (b - c) * {d / [e + f]}"
    };
    for (auto &t : tests) {
        cout << t << " -> " << (areParenthesesBalanced(t) ? "Balanced" : "Not Balanced") << '\n';
    }
    */
    return 0;
}
