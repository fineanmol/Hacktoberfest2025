
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(); 
        unordered_map<int, int> prefixSumMap;
        int currentPrefixSum = 0, subarrayCount = 0;

        prefixSumMap[0] = 1; 
        for (int i = 0; i < n; i++) {
            // Add current element to the prefix sum:
            currentPrefixSum += nums[i];


            int sumToRemove = currentPrefixSum - k;

            /* Add the number of subarrays
             with the sum to be removed*/
            subarrayCount += prefixSumMap[sumToRemove];

         
            prefixSumMap[currentPrefixSum] += 1;
        }
        return subarrayCount;
    }
};

int main()
{
    // Create an instance of solution class
    Solution solution;
    vector<int> nums = {3, 1, 2, 4};
    int k = 6;
    // Function call to get the result
    int subarrayCount = solution.subarraySum(nums, k);
    cout << "The number of subarrays is: " << subarrayCount << "\n";
    return 0;
}
