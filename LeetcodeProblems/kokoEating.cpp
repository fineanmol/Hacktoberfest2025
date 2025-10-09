// 875. Koko Eating Bananas

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canEatAll(vector<int> &piles, int mid, int h)
  {
    long long totalHours = 0;
    for (int x : piles)
    {
      totalHours += x / mid;
      if (x % mid != 0)
        totalHours++;
    }
    return totalHours <= h;
  }

  int minEatingSpeed(vector<int> &piles, int h)
  {
    int l = 1;
    int r = *max_element(piles.begin(), piles.end());

    while (l < r)
    {
      int mid = l + (r - l) / 2;
      if (canEatAll(piles, mid, h))
      {
        r = mid;
      }
      else
      {
        l = mid + 1;
      }
    }
    return l;
  }
};

int main()
{
  Solution s;
  vector<int> piles = {3, 6, 7, 11};
  int h = 8;

  cout << "Minimum eating speed: " << s.minEatingSpeed(piles, h) << endl;
}
