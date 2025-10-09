// LeetCode 76 — Minimum Window Substring

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";

    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int have = 0, needCount = need.size();
    int left = 0, right = 0;
    int minLen = INT_MAX, start = 0;

    while (right < s.size()) {
        char c = s[right];
        window[c]++;

        if (need.count(c) && window[c] == need[c])
            have++;

        while (have == needCount) {
            // Update result if this window is smaller
            if ((right - left + 1) < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            // Shrink window from left
            char leftChar = s[left];
            window[leftChar]--;
            if (need.count(leftChar) && window[leftChar] < need[leftChar])
                have--;
            left++;
        }

        right++;
    }

    return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl; // Output: "BANC"
    return 0;
}
