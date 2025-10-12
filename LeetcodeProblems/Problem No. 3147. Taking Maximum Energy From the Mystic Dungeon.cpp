// Problem Link - https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/?envType=daily-question&envId=2025-10-12
// Solution by KartikeyaG121

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(energy.size(),-1);
        int ans=INT_MIN;
        
        for(int i=energy.size()-1;i>=0;i--)
        {
            if(i+k<energy.size())
            {
                dp[i]=energy[i]+dp[i+k];
            }
            else
            {
                dp[i]=energy[i];
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
