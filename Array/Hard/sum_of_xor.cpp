#include <bits/stdc++.h>
using namespace std;

// better sol...

int getLongestZeroSumSubarrayLength(vector<int> &arr, int target)
{
          int n = arr.size();
          int count = 0;
          int xor1;
          for (int i = 0; i < n; i++)
          {
                    xor1 = 0;
                    for (int j = i; j < n; j++)
                    {
                              xor1 = xor1 ^ arr[i];
                              if (xor1 == target)
                              {
                                        count++;
                              }
                    }
          }
          return count;
}

// optimal solution  time->O(n)or O(nlogn) depends upon map you used
// space->O(n)
int subarraysWithSumK(vector<int> a, int b)
{

          int count = 0;
          int n = a.size();
          int xr = 0;

          map<int, int> hashMpp;
          hashMpp[xr]++;
          for (int i = 0; i < n; i++)
          {
                    xr = xr ^ a[i];
                    int x = xr ^ b;
                    count += hashMpp[x];
                    hashMpp[xr]++;
          }
          return count;
}

int main()
{

          return 0;
}