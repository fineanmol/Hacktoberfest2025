class Solution {
    public long maximumTripletValue(int[] nums) {
        long ans = 0;
        int maxNum = 0;   // Best nums[i] so far
        int maxDiff = 0;  // Best (nums[i] - nums[j]) so far

        for (int num : nums) {
            // Consider current num as nums[k]
            ans = Math.max(ans, (long) maxDiff * num);

            // Now treat current num as potential nums[j]
            maxDiff = Math.max(maxDiff, maxNum - num);

            // Treat current num as potential nums[i]
            maxNum = Math.max(maxNum, num);
        }

        return ans;
    }
}
