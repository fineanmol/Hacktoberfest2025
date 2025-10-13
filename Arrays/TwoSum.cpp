/*
 * Problem: Two Sum
 * 
 * Given an array of integers nums and an integer target, return indices of 
 * the two numbers such that they add up to target.
 * 
 * Example:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement exists in hash map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Store current number and its index
            numMap[nums[i]] = i;
        }
        
        return {}; // No solution found
    }
    
    // Helper function to print result
    void printResult(vector<int>& result) {
        cout << "[";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test Case 1: ";
    solution.printResult(result1);
    
    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test Case 2: ";
    solution.printResult(result2);
    
    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test Case 3: ";
    solution.printResult(result3);
    
    return 0;
}