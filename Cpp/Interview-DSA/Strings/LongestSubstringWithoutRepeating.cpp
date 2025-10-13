/*
 * Problem: Longest Substring Without Repeating Characters
 * 
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Example:
 * Input: s = "abcabcbb"
 * Output: 3 (The answer is "abc", with length 3)
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(min(m,n)) where m is charset size
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Sliding Window with HashMap (most efficient)
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            char currentChar = s[end];
            
            // If character is already seen and is within current window
            if (charIndex.find(currentChar) != charIndex.end() && 
                charIndex[currentChar] >= start) {
                start = charIndex[currentChar] + 1;
            }
            
            charIndex[currentChar] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
    
    // Approach 2: Sliding Window with HashSet
    int lengthOfLongestSubstringSet(string s) {
        unordered_set<char> charSet;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Shrink window until no duplicate
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
    
    // Approach 3: Brute Force (for comparison)
    int lengthOfLongestSubstringBruteForce(string s) {
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            unordered_set<char> seen;
            for (int j = i; j < s.length(); j++) {
                if (seen.find(s[j]) != seen.end()) {
                    break;
                }
                seen.insert(s[j]);
                maxLength = max(maxLength, j - i + 1);
            }
        }
        
        return maxLength;
    }
    
    // Get the actual longest substring (not just length)
    string getLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int maxStart = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            char currentChar = s[end];
            
            if (charIndex.find(currentChar) != charIndex.end() && 
                charIndex[currentChar] >= start) {
                start = charIndex[currentChar] + 1;
            }
            
            charIndex[currentChar] = end;
            if (end - start + 1 > maxLength) {
                maxLength = end - start + 1;
                maxStart = start;
            }
        }
        
        return s.substr(maxStart, maxLength);
    }
    
    // Extension: Find all longest substrings without repeating characters
    vector<string> getAllLongestSubstrings(string s) {
        vector<string> result;
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int start = 0;
        
        // First pass: find maximum length
        for (int end = 0; end < s.length(); end++) {
            char currentChar = s[end];
            
            if (charIndex.find(currentChar) != charIndex.end() && 
                charIndex[currentChar] >= start) {
                start = charIndex[currentChar] + 1;
            }
            
            charIndex[currentChar] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        
        // Second pass: find all substrings with maximum length
        charIndex.clear();
        start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            char currentChar = s[end];
            
            if (charIndex.find(currentChar) != charIndex.end() && 
                charIndex[currentChar] >= start) {
                start = charIndex[currentChar] + 1;
            }
            
            charIndex[currentChar] = end;
            if (end - start + 1 == maxLength) {
                string substr = s.substr(start, maxLength);
                if (find(result.begin(), result.end(), substr) == result.end()) {
                    result.push_back(substr);
                }
            }
        }
        
        return result;
    }
    
    // Extension: Find longest substring with at most k distinct characters
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        
        unordered_map<char, int> charCount;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            charCount[s[right]]++;
            
            // Shrink window until we have at most k distinct characters
            while (charCount.size() > k) {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                left++;
            }
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
    
    // Extension: Find longest substring with exactly k distinct characters
    int lengthOfLongestSubstringExactlyKDistinct(string s, int k) {
        if (k == 0) return 0;
        
        return lengthOfLongestSubstringKDistinct(s, k) - 
               lengthOfLongestSubstringKDistinct(s, k - 1);
    }
    
    // Extension: Character replacement version
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charCount;
        int maxLength = 0;
        int maxCount = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            charCount[s[right]]++;
            maxCount = max(maxCount, charCount[s[right]]);
            
            // If current window size - max frequency > k, shrink window
            if (right - left + 1 - maxCount > k) {
                charCount[s[left]]--;
                left++;
            }
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
    
public:
    // Helper function to print vector of strings
    void printStringVector(const vector<string>& vec) {
        cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            cout << "\"" << vec[i] << "\"";
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    Solution solution;
    
    cout << "=== Longest Substring Without Repeating Characters ===" << endl << endl;
    
    // Test cases
    vector<string> testCases = {
        "abcabcbb",
        "bbbbb", 
        "pwwkew",
        "",
        "au",
        "dvdf",
        "anviaj"
    };
    
    for (const string& test : testCases) {
        cout << "Input: \"" << test << "\"" << endl;
        
        int length1 = solution.lengthOfLongestSubstring(test);
        int length2 = solution.lengthOfLongestSubstringSet(test);
        int length3 = solution.lengthOfLongestSubstringBruteForce(test);
        string longestStr = solution.getLongestSubstring(test);
        
        cout << "  HashMap approach: " << length1 << endl;
        cout << "  HashSet approach: " << length2 << endl;
        cout << "  Brute force: " << length3 << endl;
        cout << "  Longest substring: \"" << longestStr << "\"" << endl;
        
        vector<string> allLongest = solution.getAllLongestSubstrings(test);
        cout << "  All longest substrings: ";
        solution.printStringVector(allLongest);
        cout << endl;
    }
    
    // Test extensions
    cout << "=== Extensions ===" << endl << endl;
    
    // Longest substring with at most k distinct characters
    cout << "Longest substring with at most k distinct characters:" << endl;
    vector<pair<string, int>> kDistinctTests = {
        {"eceba", 2},
        {"aa", 1},
        {"abaccc", 2}
    };
    
    for (const auto& test : kDistinctTests) {
        int length = solution.lengthOfLongestSubstringKDistinct(test.first, test.second);
        cout << "\"" << test.first << "\" with k=" << test.second << ": " << length << endl;
    }
    cout << endl;
    
    // Character replacement
    cout << "Longest repeating character replacement:" << endl;
    vector<pair<string, int>> replacementTests = {
        {"ABAB", 2},
        {"AABABBA", 1},
        {"ABCDE", 1}
    };
    
    for (const auto& test : replacementTests) {
        int length = solution.characterReplacement(test.first, test.second);
        cout << "\"" << test.first << "\" with k=" << test.second << ": " << length << endl;
    }
    cout << endl;
    
    // Performance comparison for large string
    string largeString = "";
    for (int i = 0; i < 10000; i++) {
        largeString += char('a' + (i % 26));
    }
    
    cout << "Performance test on string of length " << largeString.length() << ":" << endl;
    
    clock_t start = clock();
    int result1 = solution.lengthOfLongestSubstring(largeString);
    clock_t end = clock();
    cout << "HashMap approach: " << result1 << " (Time: " 
         << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms)" << endl;
    
    start = clock();
    int result2 = solution.lengthOfLongestSubstringSet(largeString);
    end = clock();
    cout << "HashSet approach: " << result2 << " (Time: " 
         << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms)" << endl;
    
    return 0;
}