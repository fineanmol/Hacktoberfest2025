#include <bits/stdc++.h>
using namespace std;

bool LinerSearch(vector<int> arr, int num)
{
          for (int i = 0; i < arr.size(); i++)
          {
                    if (arr[i] == num)
                    {
                              return true;
                    }
          }
          return false;
}

// brute force approach  time->O(n^2) and space->O(1);
int longestSuccessiveElements(vector<int> &a)
{
          int longest = 1;
          int count = 1;
          int n = a.size();
          int x;
          for (int i = 0; i < n; i++)
          {
                    x = a[i];
                    count = 1;
                    while (LinerSearch(a, x + 1) == true)
                    {
                              x = x + 1;
                              count++;
                    }
                    longest = max(longest, count);
          }

          return longest;
}

// better solution  time ->O(nlogn) and space->o(1)
int longestSuccessiveElements(vector<int> &a)
{
          // Write your code here.
          int n = a.size();
          int Longest = 1;
          int lastSmallest = INT_MIN;
          int curCount = 0;
          sort(a.begin(), a.end());
          for (int i = 0; i < n; i++)
          {
                    if (a[i] - 1 == lastSmallest)
                    {
                              curCount++;
                              lastSmallest = a[i];
                    }
                    else if (a[i] != lastSmallest)
                    {
                              curCount = 1;
                              lastSmallest = a[i];
                    }
                    Longest = max(Longest, curCount);
          }
          return Longest;
}

// optimal solution time->O(2N)(approximately ) space->O(n)
// condition are applied
int longestConsecutive(vector<int> &nums)
{
          int n = nums.size();
          int longest = 0;
          int curCount = 0;
          set<int> st;
          for (int i = 0; i < n; i++)
          {
                    st.insert(nums[i]);
          }
          for (auto it : st)
          {
                    if (st.find(it - 1) == st.end())
                    {
                              curCount = 1;
                              int x = it;
                              while (st.find(x + 1) != st.end())
                              {
                                        x = x + 1;
                                        curCount++;
                              }
                              longest = max(longest, curCount);
                    }
          }
          return longest;
}

int main()
{

          return 0;
}