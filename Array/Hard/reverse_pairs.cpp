#include <bits/stdc++.h>
using namespace std;

// brute force  time->o(n^2)  // spce->O(1);
int reverse_pair01(vector<int> &skill, int n)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (skill[i] > 2 * skill[j])
      {
        cnt++;
      }
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

void countPairs(vector<int> &arr, int low, int mid, int high)
{
  int right = mid + 1;
  for (int i = low; i <= mid; i++)
  {
    while (right <= high && arr[i] > (2 * arr[right]))
    {
      right++;
    }
    cnt += right - (mid + 1);
  }
}

void mergeSort(vector<int> &arr, int low, int high)
{
  if (low >= high)
    return;
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);      // left half
  mergeSort(arr, mid + 1, high); // right half
  countPairs(arr, low, mid, high);
  merge(arr, low, mid, high); // merging sorted halves
}

int reverse_pair02(vector<int> &skill, int n)
{
  mergeSort(skill, 0, n - 1);

  return cnt;
}
int main()
{
  int n;
  cin >> n;
  vector<int> vec;
  for (int i = 0; i < n; i++)
  {
    int c;
    cin >> c;
    vec.push_back(c);
  }
  int x = reverse_pair02(vec, n);
  cout<<x;

  return 0;
}