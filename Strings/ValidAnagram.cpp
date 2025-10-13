/*
 * Problem: Valid Anagram
 * 
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
 * typically using all the original letters exactly once.
 * 
 * Example:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1) for frequency array (assuming only lowercase letters)
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Using frequency array (most efficient for lowercase letters)
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        vector<int> freq(26, 0);
        
        // Count frequency of each character
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        // Check if all frequencies are zero
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
    
    // Approach 2: Using hash map (works for all characters)
    bool isAnagramHashMap(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> charCount;
        
        // Count characters in first string
        for (char c : s) {
            charCount[c]++;
        }
        
        // Decrease count for characters in second string
        for (char c : t) {
            charCount[c]--;
            if (charCount[c] == 0) {
                charCount.erase(c);
            }
        }
        
        return charCount.empty();
    }
    
    // Approach 3: Using sorting
    bool isAnagramSorting(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
    
    // Extension: Group anagrams together
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (string& str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            groups[sorted].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
    
    // Extension: Find all anagrams of a pattern in a string (sliding window)
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) return result;
        
        vector<int> pCount(26, 0), windowCount(26, 0);
        
        // Count characters in pattern
        for (char c : p) {
            pCount[c - 'a']++;
        }
        
        int windowSize = p.length();
        
        // Initialize first window
        for (int i = 0; i < windowSize; i++) {
            windowCount[s[i] - 'a']++;
        }
        
        // Check first window
        if (pCount == windowCount) {
            result.push_back(0);
        }
        
        // Slide the window
        for (int i = windowSize; i < s.length(); i++) {
            // Add new character
            windowCount[s[i] - 'a']++;
            // Remove old character
            windowCount[s[i - windowSize] - 'a']--;
            
            // Check if window is an anagram
            if (pCount == windowCount) {
                result.push_back(i - windowSize + 1);
            }
        }
        
        return result;
    }
    
    // Extension: Check if two strings are anagrams ignoring spaces and case
    bool isAnagramIgnoreSpaceCase(string s, string t) {
        string cleanS = "", cleanT = "";
        
        // Clean strings: remove spaces and convert to lowercase
        for (char c : s) {
            if (c != ' ') {
                cleanS += tolower(c);
            }
        }
        
        for (char c : t) {
            if (c != ' ') {
                cleanT += tolower(c);
            }
        }
        
        return isAnagram(cleanS, cleanT);
    }
    
    // Extension: Find minimum number of character swaps to make anagram
    int minSwapsToAnagram(string s, string t) {
        if (s.length() != t.length()) return -1;
        
        vector<int> freq(26, 0);
        
        // Count frequency difference
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        int swaps = 0;
        for (int count : freq) {
            if (count > 0) {
                swaps += count;
            }
        }
        
        return swaps;
    }
    
    // Extension: Check if string can be rearranged to form palindrome
    bool canFormPalindrome(string s) {
        unordered_map<char, int> charCount;
        
        for (char c : s) {
            charCount[c]++;
        }
        
        int oddCount = 0;
        for (auto& pair : charCount) {
            if (pair.second % 2 == 1) {
                oddCount++;
            }
        }
        
        // For palindrome: at most one character can have odd frequency
        return oddCount <= 1;
    }
    
public:
    // Helper function to print vector of strings
    void printStringVector(const vector<string>& vec) {
        cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            cout << "\"" << vec[i] << "\"";
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    
    // Helper function to print grouped anagrams
    void printGroupedAnagrams(const vector<vector<string>>& groups) {
        cout << "[" << endl;
        for (int i = 0; i < groups.size(); i++) {
            cout << "  ";
            printStringVector(groups[i]);
            if (i < groups.size() - 1) cout << ",";
            cout << endl;
        }
        cout << "]" << endl;
    }
};

int main() {
    Solution solution;
    
    cout << "=== Valid Anagram Problem ===" << endl << endl;
    
    // Test basic anagram cases
    vector<pair<string, string>> testCases = {
        {"anagram", "nagaram"},
        {"rat", "car"},
        {"listen", "silent"},
        {"hello", "bello"},
        {"", ""},
        {"a", "ab"}
    };
    
    for (const auto& test : testCases) {
        cout << "\"" << test.first << "\" and \"" << test.second << "\":" << endl;
        cout << "  Frequency Array: " << (solution.isAnagram(test.first, test.second) ? "true" : "false") << endl;
        cout << "  Hash Map: " << (solution.isAnagramHashMap(test.first, test.second) ? "true" : "false") << endl;
        cout << "  Sorting: " << (solution.isAnagramSorting(test.first, test.second) ? "true" : "false") << endl;
        cout << endl;
    }
    
    // Test extensions
    cout << "=== Extensions ===" << endl << endl;
    
    // Group anagrams
    cout << "Group Anagrams:" << endl;
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << "Input: ";
    solution.printStringVector(words);
    cout << endl << "Output: ";
    auto grouped = solution.groupAnagrams(words);
    solution.printGroupedAnagrams(grouped);
    cout << endl;
    
    // Find anagrams in string
    cout << "Find Anagrams in String:" << endl;
    string s = "abab", p = "ab";
    cout << "String: \"" << s << "\", Pattern: \"" << p << "\"" << endl;
    vector<int> indices = solution.findAnagrams(s, p);
    cout << "Anagram start indices: [";
    for (int i = 0; i < indices.size(); i++) {
        cout << indices[i];
        if (i < indices.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Anagram ignoring space and case
    cout << "Anagram ignoring space and case:" << endl;
    vector<pair<string, string>> spaceCases = {
        {"A man a plan a canal Panama", "Amanaplanacanalpanama"},
        {"hello world", "world hello"},
        {"The Eyes", "They See"}
    };
    
    for (const auto& test : spaceCases) {
        bool isAnagram = solution.isAnagramIgnoreSpaceCase(test.first, test.second);
        cout << "\"" << test.first << "\" and \"" << test.second << "\": " 
             << (isAnagram ? "true" : "false") << endl;
    }
    cout << endl;
    
    // Minimum swaps to make anagram
    cout << "Minimum swaps to make anagram:" << endl;
    vector<pair<string, string>> swapCases = {
        {"abc", "bca"},
        {"ab", "ba"},
        {"abc", "def"}
    };
    
    for (const auto& test : swapCases) {
        int swaps = solution.minSwapsToAnagram(test.first, test.second);
        cout << "\"" << test.first << "\" -> \"" << test.second << "\": ";
        if (swaps == -1) {
            cout << "impossible";
        } else {
            cout << swaps << " swaps";
        }
        cout << endl;
    }
    cout << endl;
    
    // Can form palindrome
    cout << "Can form palindrome:" << endl;
    vector<string> palindromeCases = {"aab", "racecar", "abc", "aabbcc"};
    for (const string& test : palindromeCases) {
        bool canForm = solution.canFormPalindrome(test);
        cout << "\"" << test << "\": " << (canForm ? "true" : "false") << endl;
    }
    
    return 0;
}