#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++) {
            int current_num = nums[i];
            int complement = target - current_num;
            if (num_map.count(complement)) {
                return {num_map[complement], i};
            }
            num_map[current_num] = i;
        }
        return {};
    }
};
