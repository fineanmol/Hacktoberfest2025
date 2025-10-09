#include <bits/stdc++.h>
using namespace std;

// brute force approach

// better permutation
vector<int> nextGreaterPermutation(vector<int> &A)
{
          next_permutation(A.begin(), A.end()); // using  c++ STL
          return A;
}

// optimal soltion time-> O(3N) and space->O(1).

void swap(int &a, int &b)
{
          int temp = a;
          a = b;
          b = temp;
}
void nextPermutation(vector<int> &nums)
{
          int n = nums.size();
          int index = -1;
          for (int i = n - 2; i >= 0; i--)
          {
                    if (nums[i] < nums[i + 1])
                    {
                              index = i;
                              break;
                    }
          }
          if (index == -1)
          {
                    reverse(nums.begin(), nums.end());
                    return;
          }
          for (int i = n - 1; i > index; i--)
          {
                    if (nums[i] > nums[index])
                    {
                              swap(nums[i], nums[index]);
                              break;
                    }
          }
          reverse(nums.begin() + index + 1, nums.end());
}

int main()
{

          return 0;
}