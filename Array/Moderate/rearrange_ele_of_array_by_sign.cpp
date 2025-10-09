#include <bits/stdc++.h>
using namespace std;

// 1.> conditon equal number of positive and negative number
// brute force time->O(2n) and space->O(n)
vector<int> alternateNumbers01(vector<int> &a)
{
          vector<int> pos;
          vector<int> neg;

          for (int i = 0; i < a.size(); i++)
          {
                    if (a[i] >= 0)
                    {
                              pos.push_back(a[i]);
                    }
                    else
                    {
                              neg.push_back(a[i]);
                    }
          }
          for (int i = 0; i < a.size() / 2; i++)
          {
                    a[2 * i] = pos[i];
                    a[2 * i + 1] = neg[i];
          }
          return a;
}

// optimal solution time->O(n) and space->O(n);
vector<int> alternateNumbers02(vector<int> &nums)
{
          vector<int> arr(nums.size(), 0);
          int posindex = 0;
          int negindex = 1;
          for (int i = 0; i < nums.size(); i++)
          {
                    if (nums[i] < 0)
                    {
                              arr[negindex] = nums[i];
                              negindex += 2;
                    }
                    else
                    {
                              arr[posindex] = nums[i];
                              posindex += 2;
                    }
          }
          return arr;
}

// 2.> conditon unequal number of positive and negative number

vector<int> alternateNumbers03(vector<int> &a)
{
          vector<int> pos;
          vector<int> neg;

          for (int i = 0; i < a.size(); i++)
          {
                    if (a[i] >= 0)
                    {
                              pos.push_back(a[i]);
                    }
                    else
                    {
                              neg.push_back(a[i]);
                    }
          }
          if (pos.size() >= neg.size())
          {
                    for (int i = 0; i < neg.size(); i++)
                    {
                              a[2 * i] = pos[i];
                              a[2 * i + 1] = neg[i];
                    }
                    int index = 2 * neg.size();
                    for (int i = neg.size(); i < pos.size(); i++)
                    {
                              a[index++] = pos[i];
                    }
          }
          else
          {
                    for (int i = 0; i < pos.size(); i++)
                    {
                              a[2 * i] = pos[i];
                              a[2 * i + 1] = neg[i];
                    }
                    int index = 2 * pos.size();
                    for (int i = pos.size(); i < neg.size(); i++)
                    {
                              a[index++] = pos[i];
                    }
          }
          return a;
}

int main()
{
          vector<int> v;
          int n;
          cout << "enter n -> no. of element  : ";
          cin >> n;
          cout << " Enter element \n";
          for (int i = 0; i < n; i++)
          {
                    int m;
                    cout << (i + 1) << " value : ";
                    cin >> m;
                    v.push_back(m);
          }
          cout << endl;
          v = alternateNumbers03(v);
          for (auto it : v)
          {
                    cout << it << ", ";
          }

          return 0;
}