#include <bits/stdc++.h>
using namespace std;

void left_Rotation_by_1(vector<int> &vec)
{
  int first = vec[0];
  for (int i = 0; i < vec.size() - 1; i++)
  {
    vec[i] = vec[i + 1];
  }
  vec[vec.size() - 1] = first;
}

// brute force approach o(n^2)
void left_Rotation_by_d01(vector<int> &vec, int d)
{
  d = d % vec.size();
  for (int i = 0; i < d; i++)
  {
    left_Rotation_by_1(vec);
  }
}

// better solution and time->O(3n) i.e O(n) and space->O(d)
void left_Rotation_by_d_02(vector<int> &vec, int d)
{
  d = d % vec.size();
  int temp[d] = {0};
  for (int i = 0; i < d; i++)
  {
    temp[i] = vec[i];
  }
  for (int i = d; i < vec.size(); i++)
  {
    vec[i - d] = vec[i];
  }
  int j = 0;
  for (int i = vec.size() - d; i < vec.size(); i++)
  {
    vec[i] = temp[j++];
    // vec[i] = temp[i-(vec.size()-d)];
  }
}

// optimal solution and time->O(n) and space->O(1)
void left_Rotation_by_d_03(int vec[], int d, int n)
{
  reverse(vec, vec + d);     // time->O(d)
  reverse(vec + d, vec + n); // time->O(n-d)
  reverse(vec, vec + n);     // time->O(n)
} // total=time->O(2n)i.e n

void left_Rotation(vector<int> &vec, int d, int n)
{
  reverse(vec.begin(), vec.begin() + d); // time->O(d)
  reverse(vec.begin() + d, vec.end());   // time->O(n-d)
  reverse(vec.begin(), vec.end());       // time->O(n)
} // total=time->O(2n)i.e n

int main()
{
  vector<int> v;
  int n, sL = 0;
  cout << "enter n : ";
  cin >> n;
  cout << " Enter element \n";
  for (int i = 0; i < n; i++)
  {
    int m;
    cout << (i + 1) << " value : ";
    cin >> m;
    v.push_back(m);
  }
  left_Rotation(v, 3, n);
  for (auto it : v)
  {
    cout << it << ", ";
  }

  // for array input
  // int n;
  // cout << "Enter no. of element : ";
  // cin >> n;
  // int arr[n] = {0};
  // vector<int> vec;
  // cout << "Enter the element\n";
  // for (int i = 0; i < n; i++)
  // {

  //           cout << (i + 1) << " value : ";
  //           cin >> arr[i];
  // }
  // left_Rotation_by_d_03(arr, 3, n);
  // cout << "Elements :  ";
  // for (int i = 0; i < n; i++)
  // {
  //           cout << arr[i] << " ";
  // }

  return 0;
}