#include <bits/stdc++.h>
using namespace std;

// Brute force approach and time->(O(n1logn +n2logn2)  + O(n1+n2 ) ) i.e O(nlogn)
// space->O(O(n1+n2)+O(n1+n2) i.e O(n)
vector<int> union01(vector<int> vec1, vector<int> vec2)
{
          set<int> st;
          for (int i = 0; i < vec1.size(); i++)
          {
                    st.insert(vec1[i]); // O(nlogn) // insert method take logn time.
          }
          for (int i = 0; i < vec2.size(); i++)
          {
                    st.insert(vec2[i]);
          }
          vector<int> vec;
          for (auto it : st)
          {
                    vec.push_back(it);
          }
          return vec;
}

// optimal solution and time -> (O(n1+n2)+O(n1)+O(n2)) i.e O(n)
// space->O(n1+n2)
vector<int> union02(vector<int> a, vector<int> b)
{
          int i = 0, j = 0;
          vector<int> unionArr;
          int n1 = a.size();
          int n2 = b.size();
          while (i < n1 && j < n2)
          {
                    if (a[i] <= b[j])
                    {
                              if (unionArr.size() == 0 || unionArr.back() != a[i])
                              {
                                        unionArr.push_back(a[i]);
                              }
                              i++;
                    }
                    else
                    {
                              if (unionArr.size() == 0 || unionArr.back() != b[j])
                              {
                                        unionArr.push_back(b[j]);
                              }
                              j++;
                    }
          }
          while (i < n1)
          {
                    if (unionArr.size() == 0 || unionArr.back() != a[i])
                    {
                              unionArr.push_back(a[i]);
                    }
                    i++;
          }
          while (j < n2)
          {
                    if (unionArr.size() == 0 || unionArr.back() != b[j])
                    {
                              unionArr.push_back(b[j]);
                    }
                    j++;
          }
          return unionArr;
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
          v = union02(v1, v2);
          cout << "Union are : ";
          for (int i = 0; i < v.size(); i++)
          {
                    cout << v[i] << " ";
          }

          return 0;
}