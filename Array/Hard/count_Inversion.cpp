#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time->O(n^2) and space->O(1).

int numberOfInversions01(vector<int> &a, int n)
{
          int cnt = 0;
          for (int i = 0; i < n; i++)
          {
                    for (int j = i + 1; j < n; j++)
                    {
                              if (a[i] > a[j])
                                        cnt++;
                    }
          }
          return cnt;
}

// optimal solution
int cnt = 0;

void merge(vector<int> &arr, int low, int mid, int high)
{
          vector<int> temp;    // temporary array
          int left = low;      // starting index of left half of arr
          int right = mid + 1; // starting index of right half of arr

          // storing elements in the temporary array in a sorted manner//

          while (left <= mid && right <= high)
          {
                    if (arr[left] <= arr[right])
                    {
                              temp.push_back(arr[left]);
                              left++;
                    }
                    else
                    {
                              cnt += mid - left + 1;
                              temp.push_back(arr[right]);
                              right++;
                    }
          }

          // if elements on the left half are still left //

          while (left <= mid)
          {
                    temp.push_back(arr[left]);
                    left++;
          }

          //  if elements on the right half are still left //
          while (right <= high)
          {
                    temp.push_back(arr[right]);
                    right++;
          }

          // transfering all elements from temporary to arr //
          for (int i = low; i <= high; i++)
          {
                    arr[i] = temp[i - low];
          }
}

void mergeSort(vector<int> &arr, int low, int high)
{
          if (low >= high)
                    return;
          int mid = (low + high) / 2;
          mergeSort(arr, low, mid);      // left half
          mergeSort(arr, mid + 1, high); // right half
          merge(arr, low, mid, high);    // merging sorted halves
}

// optimal solution  time->O(nlogn) and space->O(1).
int numberOfInversions02(vector<int> &a, int n)
{
          mergeSort(a, 0, n - 1);
          return cnt;
}
int main()
{

          return 0;
}