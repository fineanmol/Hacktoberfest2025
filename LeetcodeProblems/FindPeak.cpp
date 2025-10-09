// 162. Find Peak Element -- leetcode

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r)
    {
      int mid = (l + r) / 2;
      if (nums[mid] < nums[mid + 1])
      {
        l = mid + 1;
      }
      else
      {
        r = mid;
      }
    }
    return r;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  cout << "Peak element index: " << s.findPeakElement(nums) << endl;
}
