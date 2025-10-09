#include <bits/stdc++.h>
using namespace std;

// Longest subarray with sum k -> we have to return the maximum length of subarray whose is equal to zero

// brute force(01)  approach time->O(n^3);
int Longest_subarray_with_sum_k01(vector<int> nums, int k)
{
          int n = nums.size();
          int max_len = 0;
          for (int i = 0; i < n; i++)
          {
                    for (int j = i; j < n; j++)
                    {
                              int sum = 0;

                              for (int k = i; k <= j; k++)
                              {
                                        sum = sum + nums[k];
                              }
                              if (sum == k)
                              {
                                        max_len = max(max_len, j - i + 1);
                              }
                    }
          }
          return max_len;
}
// brute force(02)  approach time->O(n^2);
int Longest_subarray_with_sum_k02(vector<int> nums, int k)
{
          int n = nums.size();
          int max_len = 0;
          for (int i = 0; i < n; i++)
          {
                    int sum = 0;
                    for (int j = i; j < n; j++)
                    {
                              sum += nums[j];
                              if (sum == k)
                              {
                                        max_len = max(max_len, j - i + 1);
                              }
                    }
          }
          return max_len;
}

// by using hashMap
// better solution time->O(nlogn) in case map and O(n) in case of unordered map (O(n^2 ) is the worst cade of  unordered map) and space-> O(n)
// this also works for -ve number and optimal solution if -ve number are present
int Longest_subarray_with_sum_k03(vector<int> nums, int k)
{

          map<long long, int> hashMpp;
          int sum = 0;
          int maxLen = 0;
          for (int i = 0; i < nums.size(); i++)
          {
                    sum += nums[i];
                    if (sum == k)
                    {
                              maxLen = max(maxLen, i + 1);
                    }
                    int rem = sum - k;
                    if (hashMpp.find(rem) != hashMpp.end())
                    {
                              int len = i - hashMpp[rem];
                              maxLen = max(maxLen, len);
                    }
                    if (hashMpp.find(sum) == hashMpp.end())
                    {
                              hashMpp[sum] = i;
                    }
          }
          return maxLen;
}

// optimal solution for Zero and postive number (-ve number should not be present )
// time ->O(2N) i.e O(n) and space->O(1);
int Longest_subarray_with_sum_k04(vector<int> nums, int k)
{
          int right = 0, left = 0;
          int sum = nums[0];
          int n = nums.size();
          int maxLen = 0;
          while (right < n)
          {
                    while (left <= right && sum > k)
                    {
                              sum -= nums[left];
                              left++;
                    }
                    if (sum == k)
                    {
                              maxLen = max(maxLen, right - left + 1);
                    }
                    right++;
                    if (right < n)
                    {
                              sum += nums[right];
                    }
          }
          return maxLen;
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
          int req = Longest_subarray_with_sum_k04(v, 3);
          cout << "Longest length of the array  :  " << req;

          return 0;
}