// Container With Most Water

// Problem: Find two lines that together with the x-axis form a container that holds the most water.

// Solution:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            maxArea = max(maxArea, width * h);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxArea;
    }
};