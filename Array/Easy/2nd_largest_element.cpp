#include <bits/stdc++.h>
using namespace std;
//  Brute Force approach time complexity is O(nlogn) due to sorting.
int second_largest_element01(vector<int> &vec, int n)
{

          sort(vec.begin(), vec.end());
          int sec_largest = INT_MIN;
          for (int i = n - 2; i >= 0; i--)
          {
                    if (vec[i] != vec[n - 1])
                    {
                              sec_largest = vec[i];
                              break;
                    }
          }
          return sec_largest;
}

// Better Solution and O(2n) i.e O(n)
int second_largest_element02(vector<int> &vec, int n)
{
          int largest = INT_MIN;
          int sec_largest = INT_MIN;
          for (int i = 0; i < n; i++)
          {
                    if (vec[i] > largest)
                    {
                              largest = vec[i];
                    }
          }
          for (int i = 0; i < n; i++)
          {
                    if (vec[i] > sec_largest && vec[i] != largest)
                    {
                              sec_largest = vec[i];
                    }
          }
          return sec_largest;
}

// optimal solution and O(n)
int second_largest_element03(vector<int> &vec, int n)
{
          int largest = INT_MIN;
          int sec_largest = INT_MIN;
          for (int i = 0; i < n; i++)
          {
                    if (vec[i] > largest)
                    {
                              sec_largest = largest;
                              largest = vec[i];
                    }
                    else if (vec[i] < largest && vec[i] > sec_largest)
                    {
                              sec_largest = vec[i];
                    }
          }
          return sec_largest;
}

// optimal solution for second smallest  and O(n).
int second_smallest_element(vector<int> &vec, int n)
{
          int smallest = vec[0];
          int sec_smallest = INT_MAX;
          for (int i = 0; i < n; i++)
          {
                    if (vec[i] < smallest)
                    {
                              sec_smallest = smallest;
                              smallest = vec[i];
                    }
                    else if (vec[i] > smallest && vec[i] < sec_smallest)
                    {
                              sec_smallest = vec[i];
                    }
          }
          return sec_smallest;
}

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
          sL = second_smallest_element(v, n);
          cout << "Second Largest Number is : " << sL;

          return 0;
}