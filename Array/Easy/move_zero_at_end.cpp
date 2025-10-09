#include <bits/stdc++.h>
using namespace std;

// brute force approach time->O(n) and space->o(n)
vector<int> move_zero_at_end(vector<int> vec)
{
  vector<int> v;
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i] != 0)
    {
      v.push_back(vec[i]);
    }
  }
  for (int i = v.size() + 1; i <= vec.size(); i++)
  {
    v.push_back(0);
  }
  return v;
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// optimal solution and time -> O(n) and space -> O(1).
vector<int> move_zero_at_end02(vector<int> vec)
{
  int j = -1;
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i] == 0)
    {
      j = i;
      break;
    }
  }
  if (j == -1)
  {
    return vec;
  }
  for (int i = j + 1; i < vec.size(); i++)
  {
    if (vec[i] != 0)
    {
      swap(vec[i], vec[j]);
      j++;
    }
  }
  return vec;
}

// extra
// shifting zero to right
vector<int> move_zero_at_first(vector<int> vec)
{
  int n = vec.size();
  int j = -1;
  for (int i = n - 1; i > 0; i)
  {
    if (vec[i] == 0)
    {
      j = i;
      break;
    }
  }
  if (j == -1)
  {
    return vec;
  }
  for (int i = j - 1; i > 0; i--)
  {
    if (vec[i] != 0)
    {
      swap(vec[i], vec[j]);
      j++;
    }
  }
  return vec;
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
  v = move_zero_at_first(v);
  for (auto it : v)
  {
    cout << it << " ";
  }

  return 0;
}