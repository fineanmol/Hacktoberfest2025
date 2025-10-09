class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if (totalSum % 2 != 0) return false;

        int targetSum = totalSum / 2;
        vector<bool> dp(targetSum + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int currSum = targetSum; currSum >= num; --currSum) {
                dp[currSum] = dp[currSum] || dp[currSum - num];
                if (dp[targetSum]) return true;
            }
        }
        return dp[targetSum];
    }
};
