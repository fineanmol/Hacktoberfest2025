#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time->O(n^2) and space ->O(1).
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
          // Write your code here
          int n = a.size();
          int missing = -1;
          int twice = -1;
          for (int i = 1; i <= n; i++)
          {
                    int count = 0;
                    for (int j = 0; j < n; j++)
                    {
                              if (i == a[j])
                              {
                                        count++;
                              }
                    }
                    if (count == 2)
                    {
                              twice = i;
                    }
                    else if (count == 0)
                    {
                              missing = i;
                    }
                    if (missing != -1 && twice != -1)
                    {
                              break;
                    }
          }
          return {twice, missing};
}

// better solution time->O(2n) and space->O(n)
vector<int> findMissingRepeatingNumbers02(vector<int> a)
{
          // Write your code here
          int n = a.size();
          int missing = -1;
          int twice = -1;
          int hashArr[n + 1] = {0};
          for (int i = 0; i < n; i++)
          {
                    hashArr[a[i]]++;
          }
          for (int i = 1; i <= n; i++)
          {
                    if (hashArr[i] == 0)
                    {
                              missing = i;
                    }
                    else if (hashArr[i] == 2)
                    {
                              twice = i;
                    }
          }
          return {twice, missing};
}

// optimal solution time->o(n) space->O(1)
vector<int> findMissingRepeatingNumbers03(vector<int> a)
{
          // Write your code here
          int n = a.size();
          long long sn = (n * (n + 1)) / 2;
          long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;
          long long s = 0;
          long long s2 = 0;
          for (int i = 0; i < n; i++)
          {
                    s += (long long)a[i];
                    s2 += (long long)a[i] * (long long)a[i];
          }
          long long val1 = s - sn;
          long long val2 = s2 - s2n;
          val2 = val2 / val1;
          long long x = (val1 + val2) / 2;
          long long y = x - val1;
          return {(int)x, (int)y};
}
int main()
{

          return 0;
}