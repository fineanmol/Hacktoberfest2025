/*
 * Problem: Maximum Subarray (Kadane's Algorithm)
 * 
 * Given an integer array nums, find the contiguous subarray (containing at 
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
    
    // Alternative approach that also returns the subarray indices
    pair<int, pair<int, int>> maxSubArrayWithIndices(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;
        int start = 0, end = 0, tempStart = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            
            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
            
            if (currentSum < 0) {
                currentSum = 0;
                tempStart = i + 1;
            }
        }
        
        return {maxSum, {start, end}};
    }
    
    // Helper function to print subarray
    void printSubarray(vector<int>& nums, int start, int end) {
        cout << "Subarray: [";
        for (int i = start; i <= end; i++) {
            cout << nums[i];
            if (i < end) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result1 = solution.maxSubArray(nums1);
    cout << "Test Case 1 - Maximum Sum: " << result1 << endl;
    
    auto detailed1 = solution.maxSubArrayWithIndices(nums1);
    cout << "Maximum Sum: " << detailed1.first << endl;
    solution.printSubarray(nums1, detailed1.second.first, detailed1.second.second);
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {1};
    int result2 = solution.maxSubArray(nums2);
    cout << "Test Case 2 - Maximum Sum: " << result2 << endl;
    
    // Test case 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    int result3 = solution.maxSubArray(nums3);
    cout << "Test Case 3 - Maximum Sum: " << result3 << endl;
    
    auto detailed3 = solution.maxSubArrayWithIndices(nums3);
    cout << "Maximum Sum: " << detailed3.first << endl;
    solution.printSubarray(nums3, detailed3.second.first, detailed3.second.second);
    
    return 0;
}