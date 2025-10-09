#include <bits/stdc++.h>
using namespace std;
// brute force approach and time->O(n^2 ) and space-> O(n)
vector<int> intersection01(vector<int> a, vector<int> b)
{
          int visited[b.size()] = {0};
          vector<int> IsArr;
          for (int i = 0; i < a.size(); i++)
          {
                    for (int j = 0; j < b.size(); j++)
                    {
                              if (a[i] == b[j] && visited[j] == 0)
                              {
                                        IsArr.push_back(a[i]);
                                        visited[j] = 1;
                                        break;
                              }
                              // if (b[j] > a[i])
                              //           break;
                    }
          }

          return IsArr;
}

// optimal solution with time->O(n1+n2) and space-> O(n)
vector<int> intersection02(vector<int> a, vector<int> b)
{
          int i = 0, j = 0;
          vector<int> vec;
          while (i < a.size() && j < b.size())
          {
                    if (a[i] < b[j])
                    {
                              i++;
                    }
                    else if (a[i] > b[j])
                    {
                              j++;
                    }
                    else
                    {
                              vec.push_back(a[i]);
                              i++;
                              j++;
                    }
          }
          return vec;
}

int main()
{
          int n1, n2;
          cout << "Enter no. of first and second  array :  ";
          cin >> n1 >> n2;
          vector<int> v1(0, n1), v2(0, n2);
          cout << "Enter the element of first array\n";
          for (int i = 0; i < n1; i++)
          {
                    int m;
                    cout << (i + 1) << " value : ";
                    cin >> m;
                    v1.push_back(m);
          }
          cout << "Enter the element of second array\n";
          for (int i = 0; i < n2; i++)
          {
                    int m;
                    cout << (i + 1) << " value : ";
                    cin >> m;
                    v2.push_back(m);
          }
          vector<int> v;
          v = intersection02(v1, v2);
          cout << "Intersection are : ";

          for (int i = 0; i < v.size(); i++)
          {
                    cout << v[i] << " ";
          }

          return 0;
}