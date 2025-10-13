/*
 * Problem: Contains Duplicate
 * 
 * Given an integer array nums, return true if any value appears at least twice 
 * in the array, and return false if every element is distinct.
 * 
 * Example:
 * Input: nums = [1,2,3,1]
 * Output: true
 * 
 * Input: nums = [1,2,3,4]
 * Output: false
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Using Hash Set (Most Efficient)
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        
        return false;
    }
    
    // Approach 2: Using Sorting
    // Time Complexity: O(n log n), Space Complexity: O(1)
    bool containsDuplicateSorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        
        return false;
    }
    
    // Approach 3: Brute Force (For comparison)
    // Time Complexity: O(n^2), Space Complexity: O(1)
    bool containsDuplicateBruteForce(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // Find the first duplicate element
    int findFirstDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return num;
            }
            seen.insert(num);
        }
        
        return -1; // No duplicate found
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test Case 1: [1, 2, 3, 1]" << endl;
    cout << "Contains Duplicate: " << (solution.containsDuplicate(nums1) ? "true" : "false") << endl;
    cout << "First Duplicate: " << solution.findFirstDuplicate(nums1) << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test Case 2: [1, 2, 3, 4]" << endl;
    cout << "Contains Duplicate: " << (solution.containsDuplicate(nums2) ? "true" : "false") << endl;
    cout << "First Duplicate: " << solution.findFirstDuplicate(nums2) << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << "Test Case 3: [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]" << endl;
    cout << "Contains Duplicate: " << (solution.containsDuplicate(nums3) ? "true" : "false") << endl;
    cout << "First Duplicate: " << solution.findFirstDuplicate(nums3) << endl << endl;
    
    // Test different approaches
    vector<int> testNums = {7, 10, 5, 2, 3, 10, 15};
    vector<int> sortingTest = testNums; // Copy for sorting test
    
    cout << "Comparing approaches for [7, 10, 5, 2, 3, 10, 15]:" << endl;
    cout << "Hash Set Approach: " << (solution.containsDuplicate(testNums) ? "true" : "false") << endl;
    cout << "Sorting Approach: " << (solution.containsDuplicateSorting(sortingTest) ? "true" : "false") << endl;
    cout << "Brute Force Approach: " << (solution.containsDuplicateBruteForce(testNums) ? "true" : "false") << endl;
    
    return 0;
}