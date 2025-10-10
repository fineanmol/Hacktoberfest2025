#include <iostream>
#include <vector>
#include <algorithm> // for ranges::max or max_element
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(energy);
        for (int i = energy.size() - 1 - k; i >= 0; --i)
            dp[i] += dp[i + k];
        
        // ranges::max(dp) is C++20; for older compilers use:
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> energy = {5, -2, 10, 3, -1, 2};
    int k = 2;
    
    int result = sol.maximumEnergy(energy, k);
    
    cout << "Maximum Energy: " << result << endl;
    
    return 0;
}
