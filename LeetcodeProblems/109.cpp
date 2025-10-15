// Climbing Stairs

// Problem: You are climbing a staircase. It takes n steps to reach the top. Each time you can climb 1 or 2 steps. How many distinct ways can you climb to the top?
// Link: Climbing Stairs

// C++ Solution:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int first = 1, second = 2;
        for (int i = 3; i <= n; ++i) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << "Number of ways to climb " << n << " stairs: " << sol.climbStairs(n) << endl;
}