class LC209_MinimumSizeSubarraySum {
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0, sum = 0, minLength = Integer.MAX_VALUE;

        for (int right = 0; right < nums.length; right++) {
            sum += nums[right];

            // Shrink window from the left while sum >= target
            while (sum >= target) {
                minLength = Math.min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minLength == Integer.MAX_VALUE) ? 0 : minLength;
    }
}
