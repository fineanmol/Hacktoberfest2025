class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stack;
        for (int num : nums) {
            while (!stack.empty() && gcd(stack.back(), num) > 1) {
                num = lcm(stack.back(), num);
                stack.pop_back();
            }
            stack.push_back(num);
        }
        return stack;
    }
};