#include <bits/stdc++.h>
using namespace std;

//  majority_element -> In this question return the element which occurs more n/2 time where n->size of array
// brute force approach time-> O(n) space->O(n);
int majority_element01(vector<int> v)
{
          int m = v.size() / 2;
          for (int i = 0; i < v.size(); i++)
          {
                    int temp = v[i];
                    int count = 0;
                    for (int j = 0; j < v.size(); j++)
                    {
                              if (v[j] == temp)
                              {
                                        count++;
                              }
                    }
                    if (count > m)
                    {
                              return temp;
                    }
          }
}

// by using haspMap
// better solution time->O(nlogn+n) space->O(n)(depends upon the map you use)  and space->O(n);
int majority_element02(vector<int> v)
{
          int m = v.size() / 2;
          unordered_map<int, int> mpp;
          for (int i = 0; i < v.size(); i++)
          {
                    mpp[v[i]]++;
          }
          for (auto it : mpp)
          {
                    if (it.second > m)
                    {
                              return it.first;
                    }
          }
          return -1;
}

// optimal solution time->O(2n) and space->O(1)
// Moore's voting Algothirm
int majorityElement03(vector<int> &nums)
{
          int m = nums.size() / 2;
          int ele;
          int cnt = 0;
          for (int i = 0; i < nums.size(); i++)
          {
                    if (cnt == 0)
                    {
                              ele = nums[i];
                              cnt = 1;
                    }
                    else if (nums[i] == ele)
                    {
                              cnt++;
                    }
                    else
                    {
                              cnt--;
                    }
          }
          int count2 = 0;
          for (int i = 0; i < nums.size(); i++)
          {
                    if (nums[i] == ele)
                    {
                              count2++;
                    }
          }
          if (count2 > m)
          {
                    return ele;
          }
          return -1;
}

int main()
{

          return 0;
}