#include <bits/stdc++.h>
using namespace std;

// type1
// 2 sum problem ->find weather sum of the any two element array is equal to k if yes true otherwise false

// brute force approach  time->(n^2) and space->O(1).
bool sum_2_problem01(vector<int> vec, int k)
{
          int n = vec.size();
          for (int i = 0; i < n; i++)
          {
                    for (int j = 0; j < n; j++)
                    {
                              if (i == j)
                                        continue;
                              if (vec[i] + vec[j] == k)
                              {
                                        return true;
                              }
                    }
          }
          return false;
}

// better approach time-> O(nlogn)(O(N )is we use unoredered map))  and space->O(n)
bool sum_2_problem02(vector<int> vec, int k)
{
          map<int, int> hashMpp;
          for (int i = 0; i < vec.size(); i++)
          {
                    int fir = vec[i];
                    int sec = k - vec[i];
                    if (hashMpp.find(sec) != hashMpp.end())
                    {
                              return true;
                    }
                    hashMpp[fir] = i;
          }
          return false;
}

// optimal solution array should be sorted
bool sum_2_problem03(vector<int> vec, int k)
{
          int left = 0, right = vec.size() - 1;
          while (left < right)
          {
                    if ((vec[left] + vec[right]) == k)
                    {
                              return true;
                    }
                    else if ((vec[left] + vec[right]) < k)
                    {
                              left++;
                    }
                    else
                    {
                              right--;
                    }
          }
          return false;
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
          bool bol;
          // bol = sum_2_problem01(v, 8);
          // cout << bol;
          cout << sum_2_problem02(v, 8);
          return 0;
}