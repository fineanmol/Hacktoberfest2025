// 153. Find Minimum in Rotated Sorted Array -- leetcode

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findPivot(vector<int> &nums, int l, int r)
  {
    while (l < r && nums[l] == nums[l + 1])
      l++;
    while (l < r && nums[r] == nums[r - 1])
      r--;
    while (l < r)
    {
      int mid = l + (r - l) / 2;
      if (nums[mid] > nums[r])
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }

  bool binarySearch(vector<int> &nums, int l, int r, int target)
  {
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target)
        return true;
      else if (nums[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return false;
  }

  bool search(vector<int> &nums, int target)
  {
    int n = nums.size();
    if (n == 0)
      return false;
    int pivot = findPivot(nums, 0, n - 1);
    if (binarySearch(nums, 0, pivot - 1, target))
      return true;
    return binarySearch(nums, pivot, n - 1, target);
  }
};

int main()
{
  Solution s;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  cout << (s.search(nums, target) ? "Found" : "Not Found") << endl;
}
