// Longest Substring Without Repeating Characters

// Problem: Find the length of the longest substring without repeating characters.

// Solution:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int maxLength = 0, left = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (map.find(s[right]) != map.end()) {
                left = max(left, map[s[right]] + 1);
            }
            map[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};