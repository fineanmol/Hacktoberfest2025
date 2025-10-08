// House Robber II - LeetCode #213

class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        
        // Rob without first house
        int max1 = robLinear(nums, 1, nums.length - 1);
        // Rob without last house
        int max2 = robLinear(nums, 0, nums.length - 2);
        
        return Math.max(max1, max2);
    }
    
    private int robLinear(int[] nums, int start, int end) {
        if (start > end) return 0;
        
        int prev = 0;
        int curr = 0;
        
        for (int i = start; i <= end; i++) {
            int temp = Math.max(prev + nums[i], curr);
            prev = curr;
            curr = temp;
        }
        
        return curr;
    }
}
