/*
 * Problem: Product of Array Except Self
 * 
 * Given an integer array nums, return an array answer such that answer[i] is 
 * equal to the product of all the elements of nums except nums[i].
 * 
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operator.
 * 
 * Example:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1) - not counting the output array
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Optimal approach using left and right pass
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // First pass: calculate left products
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        // Second pass: calculate right products and final result
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        
        return result;
    }
    
    // Alternative approach with separate left and right arrays (for understanding)
    vector<int> productExceptSelfVerbose(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProducts(n, 1);
        vector<int> rightProducts(n, 1);
        vector<int> result(n);
        
        // Calculate left products
        for (int i = 1; i < n; i++) {
            leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
        }
        
        // Calculate right products
        for (int i = n - 2; i >= 0; i--) {
            rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
        }
        
        // Calculate final result
        for (int i = 0; i < n; i++) {
            result[i] = leftProducts[i] * rightProducts[i];
        }
        
        return result;
    }
    
    // Approach using division (if division was allowed)
    // Note: This approach has issues with zeros in the array
    vector<int> productExceptSelfWithDivision(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        // Calculate total product
        int totalProduct = 1;
        int zeroCount = 0;
        
        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
            } else {
                totalProduct *= num;
            }
        }
        
        // Handle different cases
        for (int i = 0; i < n; i++) {
            if (zeroCount > 1) {
                result[i] = 0;
            } else if (zeroCount == 1) {
                result[i] = (nums[i] == 0) ? totalProduct : 0;
            } else {
                result[i] = totalProduct / nums[i];
            }
        }
        
        return result;
    }
    
    // Helper function to print array
    void printArray(vector<int>& arr) {
        cout << "[";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Test Case 1: ";
    solution.printArray(nums1);
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Result: ";
    solution.printArray(result1);
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    cout << "Test Case 2: ";
    solution.printArray(nums2);
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Result: ";
    solution.printArray(result2);
    cout << endl;
    
    // Test case 3
    vector<int> nums3 = {2, 3, 4, 5};
    cout << "Test Case 3: ";
    solution.printArray(nums3);
    vector<int> result3 = solution.productExceptSelf(nums3);
    cout << "Result: ";
    solution.printArray(result3);
    
    // Compare with verbose approach
    vector<int> verboseResult = solution.productExceptSelfVerbose(nums3);
    cout << "Verbose Result: ";
    solution.printArray(verboseResult);
    
    return 0;
}