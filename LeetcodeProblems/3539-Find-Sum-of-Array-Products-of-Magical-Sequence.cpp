/*
Time: (m^3)kn
Space: (m^3)kn
*/

class Solution {
 public:
  int magicalSum(int m, int k, vector<int>& nums) {
    const vector<vector<int>> comb = getComb(m, m);
    vector<vector<vector<vector<int>>>> mem(
        m + 1, vector<vector<vector<int>>>(
                   k + 1, vector<vector<int>>(nums.size() + 1,
                                              vector<int>(m + 1, -1))));
    return dp(m, k, 0, 0, nums, mem, comb);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  int dp(int m, int k, int i, unsigned carry, const vector<int>& nums,
         vector<vector<vector<vector<int>>>>& mem,
         const vector<vector<int>>& comb) {
    if (m < 0 || k < 0 || (m + popcount(carry) < k))
      return 0;
    if (m == 0)
      return k == popcount(carry) ? 1 : 0;
    if (i == nums.size())
      return 0;
    if (mem[m][k][i][carry] != -1)
      return mem[m][k][i][carry];
    int res = 0;
    for (int count = 0; count <= m; ++count) {
      const long contribution = comb[m][count] * modPow(nums[i], count) % kMod;
      const int newCarry = carry + count;
      res = (res + static_cast<long>(dp(m - count, k - (newCarry % 2), i + 1,
                                        newCarry / 2, nums, mem, comb)) *
                       contribution) %
            kMod;
    }
    return mem[m][k][i][carry] = res;
  }

  // C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
  vector<vector<int>> getComb(int n, int k) {
    vector<vector<int>> comb(n + 1, vector<int>(k + 1));
    for (int i = 0; i <= n; ++i)
      comb[i][0] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= k; ++j)
        comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    return comb;
  }

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
