public class TravellingSalesMan {

    static final int INF = 1000000000;

    public static int tsp(int[][] dist) {
        int n = dist.length;
        int N = 1 << n;
        int[][] dp = new int[N][n];

        
        for (int[] row : dp)
            Arrays.fill(row, INF);

        
        dp[1][0] = 0;

        
        for (int mask = 1; mask < N; mask++) {
            for (int u = 0; u < n; u++) {
                if ((mask & (1 << u)) == 0) continue; 
                for (int v = 0; v < n; v++) {
                    if ((mask & (1 << v)) != 0) continue; 
                    int nextMask = mask | (1 << v);
                    dp[nextMask][v] = Math.min(dp[nextMask][v], dp[mask][u] + dist[u][v]);
                }
            }
        }

        
        int ans = INF;
        for (int i = 1; i < n; i++) {
            ans = Math.min(ans, dp[N - 1][i] + dist[i][0]);
        }

        return ans;
    }
}
