#include <bits/stdc++.h>
using namespace std;

// brute force  time->O(n^4) and space->O(n)
vector<vector<int>> fourSum01(vector<int> &nums, int target)
{
          // Write your code here
          set<vector<int>> st;
          int n = nums.size();
          for (int i = 0; i < n; i++)
          {
                    for (int j = i + 1; j < n; j++)
                    {
                              for (int k = j + 1; k < n; k++)
                              {
                                        for (int l = k + 1; l < n; l++)
                                        {
                                                  int sum = nums[i] + nums[j] + nums[k] + nums[l];
                                                  if (target == sum)
                                                  {
                                                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                                                            sort(temp.begin(), temp.end());
                                                            st.insert(temp);
                                                  }
                                        }
                              }
                    }
          }
          vector<vector<int>> ans(st.begin(), st.end());
          return ans;
}

// better solution  time->O(n^3* logm) and space->O(2n)
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
          // Write your code here
          set<vector<int>> st;
          int n = nums.size();
          for (int i = 0; i < n; i++)
          {
                    for (int j = i + 1; j < n; j++)
                    {
                              set<int> hashst;

                              for (int k = j + 1; k < n; k++)
                              {
                                        long long sum = nums[i] + nums[j] + nums[k];
                                        int fourth = target - sum;
                                        if (hashst.find(fourth) != hashst.end())
                                        {
                                                  vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                                                  sort(temp.begin(), temp.end());
                                                  st.insert(temp);
                                        }
                                        hashst.insert(nums[k]);
                              }
                              hashst.clear();
                    }
          }
          vector<vector<int>> ans(st.begin(), st.end());
          return ans;
}

// optimal solution tiime->O(n)
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
          vector<vector<int>> ans;
          int n = nums.size();
          sort(nums.begin(), nums.end());
          for (int i = 0; i < n; i++)
          {
                    if (i > 0 && nums[i] == nums[i - 1])
                    {
                              continue;
                    }
                    for (int j = i + 1; j < n; j++)
                    {
                              if (j != i + 1 && nums[j] == nums[j - 1])
                              {
                                        continue;
                              }
                              int k = j + 1;
                              int l = n - 1;
                              while (k < l)
                              {
                                        long long sum = nums[i] + nums[j];
                                        sum += nums[k];
                                        sum += nums[l];
                                        if (sum < target)
                                        {
                                                  k++;
                                        }
                                        else if (sum > target)
                                        {
                                                  l--;
                                        }
                                        else
                                        {
                                                  vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                                                  sort(temp.begin(), temp.end());
                                                  ans.push_back(temp);
                                                  k++;
                                                  l--;
                                                  while (k < l && nums[k] == nums[k - 1])
                                                  {
                                                            k++;
                                                  }
                                                  while (k < l && nums[l] == nums[l + 1])
                                                  {
                                                            l--;
                                                  }
                                        }
                              }
                    }
          }
          return ans;
}

int main()
{

          return 0;
}