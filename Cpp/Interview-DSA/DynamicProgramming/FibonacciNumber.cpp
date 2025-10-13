/*
 * Problem: Fibonacci Number
 * 
 * The Fibonacci numbers form a sequence where each number is the sum of the two preceding ones.
 * F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for n > 1.
 * 
 * Given n, calculate F(n).
 * 
 * Time Complexity: O(n) for DP, O(2^n) for naive recursion
 * Space Complexity: O(n) for memoization, O(1) for iterative
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Naive Recursion (Exponential Time)
    int fibRecursive(int n) {
        if (n <= 1) return n;
        return fibRecursive(n - 1) + fibRecursive(n - 2);
    }
    
    // Approach 2: Top-down DP with Memoization
    int fibMemo(int n) {
        unordered_map<int, int> memo;
        return fibMemoHelper(n, memo);
    }
    
    // Approach 3: Bottom-up DP (Tabulation)
    int fibDP(int n) {
        if (n <= 1) return n;
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
    
    // Approach 4: Space-optimized iterative
    int fibIterative(int n) {
        if (n <= 1) return n;
        
        int prev2 = 0, prev1 = 1, current;
        
        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return current;
    }
    
    // Approach 5: Matrix exponentiation (O(log n))
    int fibMatrix(int n) {
        if (n <= 1) return n;
        
        vector<vector<int>> F = {{1, 1}, {1, 0}};
        power(F, n - 1);
        return F[0][0];
    }
    
    // Generate Fibonacci sequence up to n terms
    vector<int> generateFibSequence(int n) {
        vector<int> result;
        if (n <= 0) return result;
        
        if (n >= 1) result.push_back(0);
        if (n >= 2) result.push_back(1);
        
        for (int i = 2; i < n; i++) {
            result.push_back(result[i-1] + result[i-2]);
        }
        
        return result;
    }
    
private:
    int fibMemoHelper(int n, unordered_map<int, int>& memo) {
        if (n <= 1) return n;
        
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        memo[n] = fibMemoHelper(n - 1, memo) + fibMemoHelper(n - 2, memo);
        return memo[n];
    }
    
    void multiply(vector<vector<int>>& F, vector<vector<int>>& M) {
        int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
        int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
        int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
        int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
        
        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }
    
    void power(vector<vector<int>>& F, int n) {
        if (n == 0 || n == 1) return;
        
        vector<vector<int>> M = {{1, 1}, {1, 0}};
        power(F, n / 2);
        multiply(F, F);
        
        if (n % 2 != 0) {
            multiply(F, M);
        }
    }
    
public:
    // Helper function to measure execution time
    template<typename Func>
    void measureTime(const string& approach, Func func, int n) {
        clock_t start = clock();
        int result = func(n);
        clock_t end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC * 1000; // in milliseconds
        
        cout << approach << " F(" << n << ") = " << result 
             << " (Time: " << duration << " ms)" << endl;
    }
};

int main() {
    Solution solution;
    
    cout << "=== Fibonacci Number Calculation ===" << endl << endl;
    
    // Test different approaches for small numbers
    int testN = 10;
    cout << "Computing F(" << testN << ") using different approaches:" << endl;
    
    solution.measureTime("Recursive:     ", [&](int n) { return solution.fibRecursive(n); }, testN);
    solution.measureTime("Memoization:   ", [&](int n) { return solution.fibMemo(n); }, testN);
    solution.measureTime("DP (Tabulation):", [&](int n) { return solution.fibDP(n); }, testN);
    solution.measureTime("Iterative:     ", [&](int n) { return solution.fibIterative(n); }, testN);
    solution.measureTime("Matrix Power:  ", [&](int n) { return solution.fibMatrix(n); }, testN);
    
    cout << endl;
    
    // Test for larger numbers (avoid recursive for performance)
    int largeN = 40;
    cout << "Computing F(" << largeN << ") using efficient approaches:" << endl;
    
    solution.measureTime("Memoization:   ", [&](int n) { return solution.fibMemo(n); }, largeN);
    solution.measureTime("DP (Tabulation):", [&](int n) { return solution.fibDP(n); }, largeN);
    solution.measureTime("Iterative:     ", [&](int n) { return solution.fibIterative(n); }, largeN);
    solution.measureTime("Matrix Power:  ", [&](int n) { return solution.fibMatrix(n); }, largeN);
    
    cout << endl;
    
    // Generate and display Fibonacci sequence
    cout << "First 15 Fibonacci numbers:" << endl;
    vector<int> fibSeq = solution.generateFibSequence(15);
    for (int i = 0; i < fibSeq.size(); i++) {
        cout << "F(" << i << ") = " << fibSeq[i];
        if (i < fibSeq.size() - 1) cout << ", ";
    }
    cout << endl << endl;
    
    // Edge cases
    cout << "Edge cases:" << endl;
    cout << "F(0) = " << solution.fibIterative(0) << endl;
    cout << "F(1) = " << solution.fibIterative(1) << endl;
    cout << "F(2) = " << solution.fibIterative(2) << endl;
    
    return 0;
}