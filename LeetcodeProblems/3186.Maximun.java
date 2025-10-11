class Solution {
  public long maximumTotalDamage(int[] power) {
    Map<Integer, Integer> count = new HashMap<>();

    for (final int damage : power)
      count.merge(damage, 1, Integer::sum);

    List<Integer> uniqueDamages = getSortedUniqueDamages(count);
    final int n = uniqueDamages.size();
    // dp[i][k] := the maximum damage using uniqueDamages[0..i], where k
    // indicates if the i-th damage is used
    long[][] dp = new long[n][2];

    for (int i = 0; i < n; ++i) {
      final int damage = uniqueDamages.get(i);
      if (i == 0) {
        dp[0][0] = 0;
        dp[0][1] = (long) damage * count.get(damage);
        continue;
      }
      dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = (long) damage * count.get(damage);
      if (i >= 1 && uniqueDamages.get(i - 1) != damage - 1 &&
          uniqueDamages.get(i - 1) != damage - 2) {
        dp[i][1] += Math.max(dp[i - 1][0], dp[i - 1][1]);
      } else if (i >= 2 && uniqueDamages.get(i - 2) != damage - 2) {
        dp[i][1] += Math.max(dp[i - 2][0], dp[i - 2][1]);
      } else if (i >= 3) {
        dp[i][1] += Math.max(dp[i - 3][0], dp[i - 3][1]);
      }
    }

    return Math.max(dp[n - 1][0], dp[n - 1][1]);
  }

  private List<Integer> getSortedUniqueDamages(Map<Integer, Integer> count) {
    List<Integer> uniqueDamages = new ArrayList<>(count.keySet());
    Collections.sort(uniqueDamages);
    return uniqueDamages;
  }
}
