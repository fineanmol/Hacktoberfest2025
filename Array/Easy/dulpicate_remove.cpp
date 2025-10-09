#include <bits/stdc++.h>
using namespace std;

// Removing of dulplicate from sorted array/vector

// brute force approach and time-O(nlogn)
void remove_dulpicate(vector<int> &vec, int n)
{
          set<int> st;
          for (int i = 0; i < n; i++) // n
          {
                    st.insert(vec[i]); // logn  ==> O(nlogn)
          }
          vec.clear();
          int index = 0;
          for (auto it : st)
          {
                    vec.push_back(it);
          }
}

// Optimal  solution and time-O(n) if sorted otherwise O(nlogn).
void remove_dulpicate02(vector<int> &vec, int n)
{
          // sort(vec.begin(), vec.end());
          vector<int> v;
          v.push_back(vec[0]);
          for (int i = 1; i < n; i++)
          {
                    if (vec[i] != vec[i - 1])
                    {
                              v.push_back(vec[i]);
                    }
          }
          vec.clear();
          vec = v;
}

// By using 2 pointer approach
// optimal solution and Time-O(n) and Space-O(1).
// array should be sorted
int remove_dulpicate03(vector<int> &vec)
{
          int i = 0;
          for (int j = 0; j < vec.size(); j++)
          {
                    if (vec[j] != vec[i])
                    {
                              vec[i + 1] = vec[j];
                              i++;
                    }
          }
          return i + 1;
}

int main()
{
          vector<int> v;
          int n;
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
          // for (auto it : v)
          // {
          //           cout << it << ", ";
          // }

          // for 2pointer approach
          int m = remove_dulpicate03(v);
          for (int i = 0; i < m; i++)
          {
                    cout << v[i] << ", ";
          }

          return 0;
}