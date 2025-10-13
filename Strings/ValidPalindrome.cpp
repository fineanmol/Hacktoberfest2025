/*
 * Problem: Valid Palindrome
 * 
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
 * and removing all non-alphanumeric characters, it reads the same forward and backward.
 * 
 * Example:
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true (after processing: "amanaplanacanalpanama")
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    // Approach 1: Two pointers (most efficient)
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Skip non-alphanumeric characters from right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters (convert to lowercase)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
    
    // Approach 2: Create cleaned string then check
    bool isPalindromeCleanString(string s) {
        string cleaned = "";
        
        // Clean the string
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        
        // Check if cleaned string is palindrome
        int n = cleaned.length();
        for (int i = 0; i < n / 2; i++) {
            if (cleaned[i] != cleaned[n - 1 - i]) {
                return false;
            }
        }
        
        return true;
    }
    
    // Approach 3: Using STL reverse (less efficient due to space)
    bool isPalindromeSTL(string s) {
        string cleaned = "";
        
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        
        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());
        
        return cleaned == reversed;
    }
    
    // Extension: Check if palindrome ignoring case only (keep all characters)
    bool isPalindromeIgnoreCase(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
    
    // Extension: Find longest palindromic substring
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 1;
        
        for (int i = 0; i < s.length(); i++) {
            // Check for odd length palindromes (center at i)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even length palindromes (center between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
    
    // Extension: Count palindromic substrings
    int countPalindromes(string s) {
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Count odd length palindromes
            count += countPalindromesAroundCenter(s, i, i);
            // Count even length palindromes
            count += countPalindromesAroundCenter(s, i, i + 1);
        }
        
        return count;
    }
    
    // Extension: Check if string can become palindrome with at most one deletion
    bool validPalindromeOneDelete(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                // Try deleting left character or right character
                return isPalindromeRange(s, left + 1, right) || 
                       isPalindromeRange(s, left, right - 1);
            }
            left++;
            right--;
        }
        
        return true; // Already a palindrome
    }
    
private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    
    int countPalindromesAroundCenter(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
    
    bool isPalindromeRange(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
public:
    // Helper function to demonstrate string cleaning
    string cleanString(const string& s) {
        string result = "";
        for (char c : s) {
            if (isalnum(c)) {
                result += tolower(c);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    cout << "=== Valid Palindrome Problem ===" << endl << endl;
    
    // Test cases
    vector<string> testCases = {
        "A man, a plan, a canal: Panama",
        "race a car",
        "Madam",
        "Was it a car or a cat I saw?",
        "No 'x' in Nixon",
        "",
        "a"
    };
    
    for (const string& test : testCases) {
        cout << "Input: \"" << test << "\"" << endl;
        cout << "Cleaned: \"" << solution.cleanString(test) << "\"" << endl;
        
        bool result1 = solution.isPalindrome(test);
        bool result2 = solution.isPalindromeCleanString(test);
        bool result3 = solution.isPalindromeSTL(test);
        
        cout << "Two Pointers: " << (result1 ? "true" : "false") << endl;
        cout << "Clean String: " << (result2 ? "true" : "false") << endl;
        cout << "STL Reverse: " << (result3 ? "true" : "false") << endl;
        cout << endl;
    }
    
    // Test extensions
    cout << "=== Extensions ===" << endl << endl;
    
    // Palindrome ignoring case only
    vector<string> caseTests = {"Madam", "RaceCar", "Hello"};
    cout << "Palindrome ignoring case only:" << endl;
    for (const string& test : caseTests) {
        cout << "\"" << test << "\": " << (solution.isPalindromeIgnoreCase(test) ? "true" : "false") << endl;
    }
    cout << endl;
    
    // Longest palindromic substring
    vector<string> longTests = {"babad", "cbbd", "abcdef", "racecar"};
    cout << "Longest palindromic substring:" << endl;
    for (const string& test : longTests) {
        string longest = solution.longestPalindrome(test);
        cout << "\"" << test << "\" -> \"" << longest << "\"" << endl;
    }
    cout << endl;
    
    // Count palindromic substrings
    vector<string> countTests = {"abc", "aaa", "aba"};
    cout << "Count palindromic substrings:" << endl;
    for (const string& test : countTests) {
        int count = solution.countPalindromes(test);
        cout << "\"" << test << "\": " << count << " palindromes" << endl;
    }
    cout << endl;
    
    // Valid palindrome with one deletion
    vector<string> deleteTests = {"aba", "abca", "abc", "raceacar"};
    cout << "Valid palindrome with at most one deletion:" << endl;
    for (const string& test : deleteTests) {
        bool valid = solution.validPalindromeOneDelete(test);
        cout << "\"" << test << "\": " << (valid ? "true" : "false") << endl;
    }
    
    return 0;
}