/*
 * Problem: Longest Common Subsequence (LCS)
 * 
 * Given two strings text1 and text2, return the length of their longest common subsequence.
 * A subsequence is a sequence that can be derived from another sequence by deleting some 
 * or no elements without changing the order of the remaining elements.
 * 
 * Example:
 * Input: text1 = "abcde", text2 = "ace" 
 * Output: 3 (The LCS is "ace")
 * 
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n) for 2D DP, O(min(m, n)) for space-optimized
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: 2D DP (Standard approach)
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
    
    // Approach 2: Space-optimized (using only 2 rows)
    int longestCommonSubsequenceOptimized(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        // Make text1 the shorter string for space optimization
        if (m < n) {
            swap(text1, text2);
            swap(m, n);
        }
        
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        
        return curr[n];
    }
    
    // Approach 3: Recursive with memoization
    int longestCommonSubsequenceMemo(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return lcsHelper(text1, text2, 0, 0, memo);
    }
    
    // Get the actual LCS string (not just length)
    string getLCSString(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // Backtrack to find the LCS string
        string lcs = "";
        int i = m, j = n;
        
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                lcs = text1[i - 1] + lcs;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        
        return lcs;
    }
    
    // Get all possible LCS strings
    vector<string> getAllLCS(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        vector<string> result;
        string current = "";
        getAllLCSHelper(text1, text2, m, n, dp, current, result);
        return result;
    }
    
    // Extension: Longest Common Substring (contiguous)
    int longestCommonSubstring(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxLength = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return maxLength;
    }
    
private:
    int lcsHelper(const string& text1, const string& text2, int i, int j, vector<vector<int>>& memo) {
        if (i >= text1.length() || j >= text2.length()) {
            return 0;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + lcsHelper(text1, text2, i + 1, j + 1, memo);
        } else {
            memo[i][j] = max(lcsHelper(text1, text2, i + 1, j, memo), 
                            lcsHelper(text1, text2, i, j + 1, memo));
        }
        
        return memo[i][j];
    }
    
    void getAllLCSHelper(const string& text1, const string& text2, int i, int j, 
                        const vector<vector<int>>& dp, string current, vector<string>& result) {
        if (i == 0 || j == 0) {
            reverse(current.begin(), current.end());
            result.push_back(current);
            return;
        }
        
        if (text1[i - 1] == text2[j - 1]) {
            current += text1[i - 1];
            getAllLCSHelper(text1, text2, i - 1, j - 1, dp, current, result);
        } else {
            if (dp[i - 1][j] == dp[i][j]) {
                getAllLCSHelper(text1, text2, i - 1, j, dp, current, result);
            }
            if (dp[i][j - 1] == dp[i][j]) {
                getAllLCSHelper(text1, text2, i, j - 1, dp, current, result);
            }
        }
    }
    
public:
    // Helper function to print DP table for visualization
    void printDPTable(const string& text1, const string& text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        cout << "DP Table:" << endl;
        cout << "    ";
        for (char c : text2) cout << "  " << c;
        cout << endl;
        
        for (int i = 0; i <= m; i++) {
            if (i == 0) cout << "  ";
            else cout << text1[i-1] << " ";
            
            for (int j = 0; j <= n; j++) {
                cout << "  " << dp[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    Solution solution;
    
    cout << "=== Longest Common Subsequence Problem ===" << endl << endl;
    
    // Test case 1
    string text1 = "abcde";
    string text2 = "ace";
    
    cout << "Text 1: \"" << text1 << "\"" << endl;
    cout << "Text 2: \"" << text2 << "\"" << endl << endl;
    
    int lcs1 = solution.longestCommonSubsequence(text1, text2);
    int lcs1_opt = solution.longestCommonSubsequenceOptimized(text1, text2);
    int lcs1_memo = solution.longestCommonSubsequenceMemo(text1, text2);
    string lcsStr1 = solution.getLCSString(text1, text2);
    
    cout << "LCS Length (2D DP): " << lcs1 << endl;
    cout << "LCS Length (Optimized): " << lcs1_opt << endl;
    cout << "LCS Length (Memoization): " << lcs1_memo << endl;
    cout << "LCS String: \"" << lcsStr1 << "\"" << endl;
    
    solution.printDPTable(text1, text2);
    cout << endl;
    
    // Test case 2
    string text3 = "abc";
    string text4 = "abc";
    
    cout << "Text 1: \"" << text3 << "\"" << endl;
    cout << "Text 2: \"" << text4 << "\"" << endl;
    
    int lcs2 = solution.longestCommonSubsequence(text3, text4);
    string lcsStr2 = solution.getLCSString(text3, text4);
    
    cout << "LCS Length: " << lcs2 << endl;
    cout << "LCS String: \"" << lcsStr2 << "\"" << endl << endl;
    
    // Test case 3
    string text5 = "abc";
    string text6 = "def";
    
    cout << "Text 1: \"" << text5 << "\"" << endl;
    cout << "Text 2: \"" << text6 << "\"" << endl;
    
    int lcs3 = solution.longestCommonSubsequence(text5, text6);
    string lcsStr3 = solution.getLCSString(text5, text6);
    
    cout << "LCS Length: " << lcs3 << endl;
    cout << "LCS String: \"" << lcsStr3 << "\"" << endl << endl;
    
    // Test extension: Longest Common Substring
    cout << "=== Extension: Longest Common Substring ===" << endl;
    string sub1 = "GeeksforGeeks";
    string sub2 = "GeeksQuiz";
    
    cout << "String 1: \"" << sub1 << "\"" << endl;
    cout << "String 2: \"" << sub2 << "\"" << endl;
    cout << "Longest Common Substring Length: " << solution.longestCommonSubstring(sub1, sub2) << endl;
    
    return 0;
}