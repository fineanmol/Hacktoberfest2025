#include <bits/stdc++.h>
using namespace std;

// Linear search time->O(n).
int linear_search(vector<int> vec, int num)
{
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i] == num)
    {
      return i;
    }
  }
  return -1;
}

int Binary_search(vector<int> vec, int num)
{
  sort(vec.begin(), vec.end());
  int l = 0;
  int h = vec.size() - 1;
  int mid = (l + h) / 2;
  while (l <= h)
  {
    if (vec[mid] == num)
    {
      return mid;
    }
    else if (vec[mid] < num)
    {
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }
}

int main()
{
  vector<int> v;
  int n;
  cout << "enter no. element(n) : ";
  cin >> n;
  cout << " Enter element \n";
  for (int i = 0; i < n; i++)
  {
    int m;
    cout << (i + 1) << " value : ";
    cin >> m;
    v.push_back(m);
  }
  int m = Binary_search(v, 5);
  cout << m << endl;
  for (auto it : v)
  {
    cout << it;
  }

  return 0;
}