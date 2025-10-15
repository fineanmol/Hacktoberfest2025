// LeetCode Problem - 73   Sort Colors  (Level Medium)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        // Counting the number of 0s,1s and 2s in array
        for (int n : nums) {
            if (n == 0) count0++;
            else if (n == 1) count1++;
            else count2++;
        }

        // Rewriting array in sorted order
        int index = 0;
        while (count0--) nums[index++] = 0;
        while (count1--) nums[index++] = 1;
        while (count2--) nums[index++] = 2;
    }
};
