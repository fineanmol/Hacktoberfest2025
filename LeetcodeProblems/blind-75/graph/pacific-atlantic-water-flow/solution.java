// Pacific Atlantic Water Flow - LeetCode #417

import java.util.*;

class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> result = new ArrayList<>();
        if (heights == null || heights.length == 0 || heights[0].length == 0) return result;
        
        int m = heights.length;
        int n = heights[0].length;
        
        boolean[][] pacific = new boolean[m][n];
        boolean[][] atlantic = new boolean[m][n];
        
        // DFS from borders
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, Integer.MIN_VALUE, i, 0);
            dfs(heights, atlantic, Integer.MIN_VALUE, i, n - 1);
        }
        
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, Integer.MIN_VALUE, 0, j);
            dfs(heights, atlantic, Integer.MIN_VALUE, m - 1, j);
        }
        
        // Find intersection
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.add(Arrays.asList(i, j));
                }
            }
        }
        
        return result;
    }
    
    private void dfs(int[][] heights, boolean[][] visited, int height, int x, int y) {
        int m = heights.length;
        int n = heights[0].length;
        
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || heights[x][y] < height) return;
        
        visited[x][y] = true;
        
        dfs(heights, visited, heights[x][y], x - 1, y);
        dfs(heights, visited, heights[x][y], x + 1, y);
        dfs(heights, visited, heights[x][y], x, y - 1);
        dfs(heights, visited, heights[x][y], x, y + 1);
    }
}
