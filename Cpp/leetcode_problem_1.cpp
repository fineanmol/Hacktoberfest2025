// Adjacent Increasing Subarrays Detection I

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 1, precont = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                precont = cnt;
                cnt = 1;
            }
            ans =max(ans, min(precont, cnt));
            ans =max(ans, cnt / 2);
        }
        return ans >= k;
    }
};