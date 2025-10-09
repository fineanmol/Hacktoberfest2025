#include <bits/stdc++.h>
using namespace std;

// leader -> return those element whose right part are small in array.

// brute force approach time->O(n^2) space->O(n)(in returning the rezuired array)
vector<int> superiorElements(vector<int> &a)
{
          vector<int> v;
          int n = a.size();
          bool leader;
          for (int i = 0; i < n; i++)
          {
                    leader = true;
                    for (int j = i + 1; j < n; j++)
                    {
                              if (a[i] <= a[j])
                              {
                                        leader = false;
                                        break;
                              }
                    }
                    if (leader == true)
                    {
                              v.push_back(a[i]);
                    }
          }
          reverse(v.begin(), v.end());
          return v;
}

// optimal solution  time->O(n) space ->O(n)
vector<int> superiorElements(vector<int> &a)
{
          vector<int> v;
          int n = a.size();
          v.push_back(a[n - 1]);
          int max = a[n - 1];
          for (int i = n - 2; i >= 0; i--)
          {
                    if (a[i] > max)
                    {
                              max = a[i];
                              v.push_back(max);
                    }
          }
          return v;
}

int main()
{

          return 0;
}