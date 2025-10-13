/*
 * Problem: Climbing Stairs
 * 
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Example:
 * Input: n = 2
 * Output: 2 (1+1, 2)
 * 
 * Input: n = 3  
 * Output: 3 (1+1+1, 1+2, 2+1)
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1) for optimized version
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Space-optimized DP (most efficient)
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int prev2 = 1; // ways(0) = 1
        int prev1 = 2; // ways(1) = 1, ways(2) = 2
        int current;
        
        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2; // ways(i) = ways(i-1) + ways(i-2)
            prev2 = prev1;
            prev1 = current;
        }
        
        return current;
    }
    
    // Approach 2: DP with array
    int climbStairsDP(int n) {
        if (n <= 2) return n;
        
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
    
    // Approach 3: Recursive with memoization
    int climbStairsMemo(int n) {
        unordered_map<int, int> memo;
        return climbStairsHelper(n, memo);
    }
    
    // Approach 4: Naive recursion (for comparison - inefficient)
    int climbStairsRecursive(int n) {
        if (n <= 2) return n;
        return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
    }
    
    // Extension: Climb 1, 2, or 3 steps at a time
    int climbStairsThreeSteps(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        
        int prev3 = 1; // ways(1) = 1
        int prev2 = 2; // ways(2) = 2  
        int prev1 = 4; // ways(3) = 4
        int current;
        
        for (int i = 4; i <= n; i++) {
            current = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return current;
    }
    
    // Extension: Print all possible ways to reach step n
    vector<vector<int>> getAllWays(int n) {
        vector<vector<int>> result;
        vector<int> current;
        getAllWaysHelper(n, current, result);
        return result;
    }
    
    // Extension: Minimum cost climbing stairs
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n <= 2) return n == 1 ? cost[0] : min(cost[0], cost[1]);
        
        int prev2 = cost[0];
        int prev1 = cost[1];
        int current;
        
        for (int i = 2; i < n; i++) {
            current = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = current;
        }
        
        return min(prev1, prev2); // Can start from step 0 or 1
    }
    
private:
    int climbStairsHelper(int n, unordered_map<int, int>& memo) {
        if (n <= 2) return n;
        
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);
        return memo[n];
    }
    
    void getAllWaysHelper(int remaining, vector<int>& current, vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        
        if (remaining < 0) return;
        
        // Take 1 step
        current.push_back(1);
        getAllWaysHelper(remaining - 1, current, result);
        current.pop_back();
        
        // Take 2 steps
        current.push_back(2);
        getAllWaysHelper(remaining - 2, current, result);
        current.pop_back();
    }
    
public:
    // Helper function to print all ways
    void printAllWays(const vector<vector<int>>& ways) {
        cout << "All possible ways:" << endl;
        for (int i = 0; i < ways.size(); i++) {
            cout << "Way " << i + 1 << ": ";
            for (int j = 0; j < ways[i].size(); j++) {
                cout << ways[i][j];
                if (j < ways[i].size() - 1) cout << " + ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution solution;
    
    cout << "=== Climbing Stairs Problem ===" << endl << endl;
    
    // Test basic cases
    for (int n = 1; n <= 6; n++) {
        int ways = solution.climbStairs(n);
        cout << "n = " << n << ": " << ways << " ways" << endl;
        
        if (n <= 4) { // Only show all ways for small n to avoid clutter
            vector<vector<int>> allWays = solution.getAllWays(n);
            solution.printAllWays(allWays);
            cout << endl;
        }
    }
    
    cout << "=== Performance Comparison ===" << endl;
    int testN = 35;
    
    clock_t start, end;
    
    // Test efficient approaches
    start = clock();
    int result1 = solution.climbStairs(testN);
    end = clock();
    cout << "Space-optimized DP: " << result1 
         << " (Time: " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms)" << endl;
    
    start = clock();
    int result2 = solution.climbStairsDP(testN);
    end = clock();
    cout << "DP with array: " << result2 
         << " (Time: " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms)" << endl;
    
    start = clock();
    int result3 = solution.climbStairsMemo(testN);
    end = clock();
    cout << "Memoization: " << result3 
         << " (Time: " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms)" << endl;
    
    cout << endl;
    
    // Test extension: 3 steps at a time
    cout << "=== Extension: 1, 2, or 3 steps ===" << endl;
    for (int n = 1; n <= 6; n++) {
        int ways = solution.climbStairsThreeSteps(n);
        cout << "n = " << n << ": " << ways << " ways (with 1, 2, or 3 steps)" << endl;
    }
    
    cout << endl;
    
    // Test extension: minimum cost climbing
    cout << "=== Extension: Minimum Cost Climbing ===" << endl;
    vector<int> cost1 = {10, 15, 20};
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    
    cout << "Cost array [10, 15, 20]: Minimum cost = " 
         << solution.minCostClimbingStairs(cost1) << endl;
    cout << "Cost array [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]: Minimum cost = " 
         << solution.minCostClimbingStairs(cost2) << endl;
    
    return 0;
}