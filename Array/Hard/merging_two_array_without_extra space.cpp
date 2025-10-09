#include <bits/stdc++.h>
using namespace std;

// problem state that  merge two sorted array without using extra space
// time->O(n+m)+O(n+m)  ans space ->O(n)
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
          // Write your code here.
          int n = a.size();
          int m = b.size();
          vector<long long> temp;
          int i1 = 0, i2 = 0;
          int index = 0;
          while (i1 < n && i2 < m)
          {
                    if (a[i1] <= b[i2])
                    {
                              // temp[index++]=a[i1++];
                              temp.push_back(a[i1++]);
                    }
                    else
                    {
                              // temp[index++]=b[i2++];
                              temp.push_back(b[i2++]);
                    }
          }
          while (i1 < n)
          {
                    // temp[index++]=a[i1++];
                    temp.push_back(a[i1++]);
          }
          while (i2 < m)
          {
                    // temp[index++]=b[i2++];
                    temp.push_back(b[i2++]);
          }
          for (int i = 0; i < m + n; i++)
          {
                    if (i < n)
                    {
                              a[i] = temp[i];
                    }
                    else
                    {
                              b[i - n] = temp[i];
                    }
          }
}

// optimal  solution 1.>
// time->O(n) space->O(1)
void mergeTwoSortedArraysWithoutExtraSpace02(vector<long long> &nums1, vector<long long> &nums2)
{
          // Write your code here.
          int m = nums1.size();
          int n = nums2.size();
          int i1 = m - 1;
          int i2 = 0;
          while (i1 >= 0 && i2 < m)
          {
                    if (nums1[i1] > nums2[i2])
                    {
                              swap(nums1[i1], nums2[i2]);
                              i1--;
                              i2++;
                    }
                    else
                    {
                              break;
                    }
          }
          sort(nums1.begin(), nums1.end());
          sort(nums2.begin(), nums2.end());
}

// function used in optimal sol. 2////
void swap_if_greater(long long &a, long long &b)
{
          if (a > b)
          {
                    long long temp = a;
                    a = b;
                    b = temp;
          }
}

// optimal solution 2
// time ->O(n)
// space->O((log(n+m)(n+m))) and  space->O(1).
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &nums1, vector<long long> &nums2)
{
          // Write your code here.
          int n = nums1.size();
          int m = nums2.size();
          int len = n + m;
          int gap = (len / 2) + (len % 2);
          while (gap > 0)
          {
                    int left = 0;
                    int right = left + gap;
                    while (right < len)
                    {
                              if (left < n && right >= n)
                              {
                                        swap_if_greater(nums1[left], nums2[right - n]);
                              }
                              else if (left >= n)
                              {
                                        swap_if_greater(nums2[left - n], nums2[right - n]);
                              }
                              else
                              {
                                        swap_if_greater(nums1[left], nums1[right]);
                              }
                              left++;
                              right++;
                    }
                    if (gap == 1)
                    {
                              break;
                    }

                    gap = (gap / 2) + (gap % 2);
          }
}

int main()
{

          return 0;
}