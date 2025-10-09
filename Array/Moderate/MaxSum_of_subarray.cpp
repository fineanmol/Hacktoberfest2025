#include <bits/stdc++.h>
using namespace std;

// brute force   time->o(n^2)
long long maxSubarraySum01(vector<int> arr, int n)
{
          // Write your code here.
          long long maxi = INT_MIN;
          for (int i = 0; i < n; i++)
          {
                    long long sum = 0;

                    for (int j = i; j < n; j++)
                    {
                              for (int k = i; k = j; k++)
                              {
                                        sum = sum + arr[i];
                              }
                              maxi = max(maxi, sum);
                    }
          }
          return maxi;
}

// better solution   time->o(n^2)
long long maxSubarraySum02(vector<int> arr, int n)
{
          // Write your code here.
          long long maxi = INT_MIN;
          for (int i = 0; i < n; i++)
          {
                    long maxsum = 0;
                    long long sum = 0;
                    for (int j = i; j < n; j++)
                    {
                              sum += arr[j];
                              maxsum = maxsum >= sum ? maxsum : sum; // maxsum=max(maxsum,sum);
                    }
                    maxi = maxi >= maxsum ? maxi : maxsum; // maxi=max(maxsum,maxi);
          }

          return maxi;
}

// optimal solution  this approach is also known as  ## kadane's algorithm  ##//
// time O(n) space->O(1);
long long maxSubarraySum03(vector<int> arr, int n)
{
          // Write your code here.
          long long maxi = LONG_MIN;
          long long sum = 0;
          for (int i = 0; i < n; i++)
          {
                    sum += arr[i];
                    if (sum > maxi)
                    {
                              maxi = sum;
                    }
                    if (sum < 0)
                    {
                              sum = 0;
                    }
          }
          if (maxi < 0)
          {
                    return 0;
          }
          return maxi;
}

// there is another subproblem is that to print that sub array which giver the maximum limit.

vector<int> Subarray_with_MaxSum(vector<int> arr, int n)
{
          // Write your code here.
          long long maxi = LONG_MIN;
          long long sum = 0;
          int ansStart = 0, ansEnd = 0;
          int start = 0;
          for (int i = 0; i < n; i++)
          {
                    if (sum == 0)
                    {
                              start = i;
                    }
                    sum += arr[i];
                    if (sum > maxi)
                    {
                              maxi = sum;
                              ansStart = start;
                              ansEnd = i;
                    }
                    if (sum < 0)
                    {
                              sum = 0;
                    }
          }
          vector<int> v;
          for (int i = ansStart; i <= ansEnd; i++)
          {
                    v.push_back(arr[i]);
          }
          return v;
}

int main()
{
          vector<int> v;
          int n;
          cout << "enter n -> no. of element  : ";
          cin >> n;
          cout << " Enter element \n";
          for (int i = 0; i < n; i++)
          {
                    int m;
                    cout << (i + 1) << " value : ";
                    cin >> m;
                    v.push_back(m);
          }
          cout << endl;
          vector<int> vc;
          vc = Subarray_with_MaxSum(v, n);
          cout << "SubArray  that give maximum Sum :: ";
          for (auto it : vc)
          {
                    cout << it << ", ";
          }
          return 0;
}