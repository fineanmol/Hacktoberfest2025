

#include <bits/stdc++.h>
using namespace std;

bool areParenthesesBalanced(const string& s) {
    static const unordered_map<char, char> match = {
        {')', '('}, {']', '['}, {'}', '{'}
    };

    vector<char> st;
    st.reserve(s.size()); // preallocate to avoid resizing

    for (char ch : s) {
        if (match.count(ch)) {
            if (st.empty() || st.back() != match.at(ch))
                return false;
            st.pop_back();
        } else if (ch == '(' || ch == '[' || ch == '{') {
            st.push_back(ch);
        }
    }

    return st.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter string to check (single line): ";
    string line;
    if (!getline(cin, line)) return 0;

    cout << (areParenthesesBalanced(line) ? "Balanced\n" : "Not Balanced\n");
    return 0;
}
