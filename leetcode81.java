/*
Problem Description
You are given an integer array nums that was originally sorted in non-decreasing order but then possibly rotated at some unknown pivot. The array may contain duplicates.

Given a target value target, write a function to determine if target is in nums.

Return true if target is found in the array, otherwise return false.

Input
nums: An integer array with length 
1
≤
nums.length
≤
5000
1≤nums.length≤5000.

target: An integer value to locate in the array.

Output
Return a boolean value:

true if the target exists in nums.

false if the target does not exist in nums.

Constraints
1
≤
nums.length
≤
5000
1≤nums.length≤5000

−
10
4
≤
nums
[
i
]
,
target
≤
10
4
−10 
4
 ≤nums[i],target≤10 
4
 

nums may contain duplicates.

Array nums is a rotated version of a sorted array.

The algorithm should attempt to achieve better than linear search time, ideally 
O
(
log
⁡
n
)
O(logn), but worst case may degrade to 
O
(
n
)
O(n) due to duplicates.

Example
Input:

text
nums = [2,5,6,0,0,1,2]
target = 0
Output:

text
true
Explanation:
The target 0 exists in the array.

Input:

text
nums = [2,5,6,0,0,1,2]
target = 3
Output:

text
false
Explanation:
*/

public class Solution {
    public boolean search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // If left to mid is sorted
            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // If mid to right is sorted
            else if (nums[mid] < nums[left]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            // When nums[left] == nums[mid], we cannot determine the sorted part, so shrink the search space
            else {
                left++;
            }
        }
        return false;
    }
}
