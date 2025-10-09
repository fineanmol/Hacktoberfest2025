#include <bits/stdc++.h>
using namespace std;

void right_Rotation_by_1(int arr[], int n)
{
  int temp = arr[n - 1];
  for (int i = n - 1; i >= 1; i--)
  {
    arr[i] = arr[i - 1];
  }
  arr[0] = temp;
}
// brute force approach o(n^2)
void right_Rotation_by_d01(int arr[], int n, int d)
{
  d = d % n;
  for (int i = 0; i < d; i++)
  {
    right_Rotation_by_1(arr, n);
  }
}

// better solution and time->O(3n) i.e O(n) and space->O(d)
void right_Rotation_by_d_02(int arr[], int d, int n)
{
  d = d % n;
  int temp1[d] = {0};
  int temp2 = arr[0];
  for (int i = n - d; i < n; i++)
  {
    temp1[i - (n - d)] = arr[i];
  }
  int m = n - 1;
  for (int i = n - (d + 1); i >= 0; i--)
  {
    arr[m--] = arr[i];
  }
  for (int i = 0; i <= d; i++)
  {
    arr[i] = temp1[i];
  }
  arr[++m] = temp2;
}

// better solution and time->O(n) and space->O(1)
void right_Rotation_by_d_03(int vec[], int d, int n)
{
  d = d % n;                 // imp step helpful in solving runtime error
  reverse(vec, vec + n);     // time->O(n)
  reverse(vec, vec + d);     // time->O(n-d)
  reverse(vec + d, vec + n); // time->O(d)
} // total=time->O(2n)i.e n

int main()
{
  // for array input
  int n;
  cout << "Enter no. of element : ";
  cin >> n;
  int arr[n] = {0};
  cout << "Enter the element\n";
  for (int i = 0; i < n; i++)
  {
    cout << (i + 1) << " value : ";
    cin >> arr[i];
  }
  right_Rotation_by_d_02(arr, 3, n);
  cout << "Elements :  ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}