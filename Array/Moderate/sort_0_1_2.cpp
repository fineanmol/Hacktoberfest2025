#include <bits/stdc++.h>
using namespace std;

// brute force approach is to use merge sort
// better solution time->O(2n) and space->O(1)
void sortArray(vector<int> &arr, int n)
{
          int count_0 = 0;
          int count_1 = 0;
          int count_2 = 0;
          for (int i = 0; i < n; i++)
          {
                    if (arr[i] == 0)
                    {
                              count_0++;
                    }
                    else if (arr[i] == 1)
                    {
                              count_1++;
                    }
                    else
                    {
                              count_2++;
                    }
          }
          arr.clear();

          for (int i = 0; i < count_0; i++)
          {
                    arr.push_back(0);
          }
          for (int i = 0; i < count_1; i++)
          {
                    arr.push_back(1);
          }
          for (int i = 0; i < count_2; i++)
          {
                    arr.push_back(2);
          }
}

// IMP
//  optimal solution time->O(n) and space->O(n);
// this approach is also knows as Dutch National flag Algos
void sortColors(vector<int> &nums)
{

          int low = 0, mid = 0, high = nums.size() - 1;
          while (mid <= high)
          {
                    if (nums[mid] == 0)
                    {
                              swap(nums[low], nums[mid]);
                              mid++;
                              low++;
                    }
                    else if (nums[mid] == 1)
                    {
                              mid++;
                    }
                    else
                    {
                              swap(nums[mid], nums[high]);
                              high--;
                    }
          }
}

int main()
{

          return 0;
}