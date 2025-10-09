#include <bits/stdc++.h>
using namespace std;

//  Brute Force approach time complexity is O(nlogn) due to sorting.
vector<int> largest_element(vector<int> &vec, int n)
{
          sort(vec.begin(), vec.end());
          return vec;
}

int largest_element02(vector<int> &vec, int n)
{
          // better solution with O(n).
          int largest = INT_MIN;
          for (int i = 0; i < n; i++)
          {
                    if (vec[i] > largest)
                    {
                              largest = vec[i];
                    }
          }
          return largest;
}

//

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
          for (auto it : v)
          {
                    cout << it << ", ";
          }

          // v = largest_element(v, n);
          // cout << endl;
          // for (auto it : v)
          // {
          //           cout << it << ", ";
          // }
          // cout << endl;
          // cout << "Largest Element : " << v[n - 1];

          int l = largest_element02(v, n);
          cout << "Largest Element : " << l;

          return 0;
}