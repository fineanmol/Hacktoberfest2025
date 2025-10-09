#include <bits/stdc++.h>
using namespace std;

// type-2
// 2 sum problem ->sum of the any two element array is equal to k return their index.

// brute force approach  time->(n^2) and space->O(1).
vector<int> sum_2_problem01(vector<int> vec, int k)
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
        return {vec[i], vec[j]};
      }
    }
  }
  return {-1};
}
// better approach time-> O(n) (O(N is we use unoredered map))  space->O(n)
vector<int> sum_2_problem02(vector<int> vec, int k)
{
  map<int, int> hashMpp;
  for (int i = 0; i < vec.size(); i++)
  {
    int fir = vec[i];
    int sec = k - vec[i];
    if (hashMpp.find(sec) != hashMpp.end())
    {
      return {hashMpp[sec], i}; //  values-> {fir, sec};
    }
    hashMpp[fir] = i;
  }
  return {-1};
}

// optimal solution array should be sorted
vector<int> sum_2_problem03(vector<int> vec, int k)
{
  sort(vec.begin(), vec.end());
  int left = 0, right = vec.size() - 1;
  while (left < right)
  {
    if ((vec[left] + vec[right]) == k)
    {
      return {left, right}; // value->{vec[left], vec[right]};
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
}
//  rough
//    int n=nums.size();
//         for(int i=0; i<n-1; i++)
//         {
//             for(int j=i+1; j<n; j++)
//             {
//                 if(nums[i]+nums[j]==target)
//                 {
//                     return {i,j};
//                 }
//             }
//         }
//         return {};

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
  vector<int> vec;
  vec = sum_2_problem03(v, 6);
  cout << "Elements are : ";
  for (auto it : vec)
  {
    cout << it << ", ";
  }

  return 0;
}