#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time ->O(n^3) and space->O(1)
// by selecting each subarray using 3 loop.


// better solution  time->O(n^2) ans space->O(1)
int subarrayWithMaxProduct(vector<int> &arr)
{
          // Write your code here.
          int n = arr.size();
          int maxiProduct = -2147483648;
          for (int i = 0; i < n; i++)
          {
                    int product = 1;
                    for (int j = i; j < n; j++)
                    {
                              product = product * arr[j];
                              maxiProduct = max(maxiProduct, product);
                    }
          }
          return maxiProduct;
}
// optimal solution time->O(n) and space->O(1)
int maxProduct(vector<int> &nums)
{
          int prefix = 1;
          int suffix = 1;
          int maxiProduct = -2147483648;
          for (int i = 0; i < nums.size(); i++)
          {
                    if (prefix == 0)
                    {
                              prefix = 1;
                    }
                    if (suffix == 0)
                    {
                              suffix = 1;
                    }

                    prefix = prefix * nums[i];
                    suffix = suffix * nums[nums.size() - i - 1];
                    maxiProduct = max(maxiProduct, max(prefix, suffix));
          }
          return maxiProduct;
}

int main()
{

          return 0;
}