#include <bits/stdc++.h>
using namespace std;

// brute approach time->O(n^2) space->O(1)
vector<int> majorityElement(vector<int> v)
{
          int n = v.size();
          int m = n / 3;
          vector<int> nums;
          int count;
          for (int i = 0; i < n; i++)
          {
                    count = 0;
                    if (nums.size() == 0 || nums[0] != v[i])
                    {
                              for (int j = 0; j < n; j++)
                              {
                                        if (v[j] == v[i])
                                        {
                                                  count++;
                                        }
                              }
                              if (count > m)
                              {
                                        nums.push_back(v[i]);
                              }
                    }
                    if (nums.size() >= 2)
                    {
                              break;
                    }
          }
          return nums;
}

// better solution time->O(nlogn) or O(n)(depends on map it will use) space-> O(n)
vector<int> majorityElement(vector<int> v)
{
          // Write your code here
          int n = v.size();
          int mini = n / 3 + 1;
          vector<int> ls;
          map<int, int> mpp;
          for (int i = 0; i < v.size(); i++)
          {
                    mpp[v[i]]++;
                    if (mpp[v[i]] == mini)
                    {
                              ls.push_back(v[i]);
                    }
                    if (ls.size() == 2)
                    {
                              break;
                    }
          }
          sort(ls.begin(), ls.end());
          return ls;
}

// optimal solution  time->O(2N) space->O(1)
vector<int> majorityElement(vector<int> &nums)
{
          int n = nums.size();
          vector<int> ls;
          int mini = n / 3 + 1;
          int ele1 = INT_MIN;
          int ele2 = INT_MIN;
          int count1 = 0, count2 = 0;
          for (int i = 0; i < n; i++)
          {
                    if (count1 == 0 && ele2 != nums[i])
                    {
                              count1 = 1;
                              ele1 = nums[i];
                    }
                    else if (count2 == 0 && ele1 != nums[i])
                    {
                              count2 = 1;
                              ele2 = nums[i];
                    }
                    else if (ele1 == nums[i])
                    {
                              count1++;
                    }
                    else if (ele2 == nums[i])
                    {
                              count2++;
                    }
                    else
                    {
                              count1--;
                              count2--;
                    }
          }
          count1 = 0;
          count2 = 0;
          for (int i = 0; i < n; i++)
          {
                    if (nums[i] == ele1)
                    {
                              count1++;
                    }
                    else if (nums[i] == ele2)
                    {
                              count2++;
                    }
          }
          if (count1 >= mini)
          {
                    ls.push_back(ele1);
          }
          if (count2 >= mini)
          {
                    ls.push_back(ele2);
          }
          sort(ls.begin(), ls.end());
          return ls;
}

int main()
{

          return 0;
}