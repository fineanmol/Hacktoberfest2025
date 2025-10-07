import java.util.Arrays;

class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        long total = 0;
        int left = 0, res = 1;

        for (int right = 0; right < nums.length; right++) {
            total += nums[right];
            // If making all elements in window [left, right] equal to nums[right] costs more than k, move left pointer
            while ((long) nums[right] * (right - left + 1) - total > k) {
                total -= nums[left];
                left++;
            }
            res = Math.max(res, right - left + 1);
        }
        return res;
    }
}
