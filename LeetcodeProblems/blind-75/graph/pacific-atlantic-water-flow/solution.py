# Pacific Atlantic Water Flow - LeetCode #417

from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        result = []
        if not heights or not heights[0]:
            return result
        
        m = len(heights)
        n = len(heights[0])
        
        pacific = [[False] * n for _ in range(m)]
        atlantic = [[False] * n for _ in range(m)]
        
        # DFS from borders
        for i in range(m):
            self.dfs(heights, pacific, float('-inf'), i, 0)
            self.dfs(heights, atlantic, float('-inf'), i, n - 1)
        
        for j in range(n):
            self.dfs(heights, pacific, float('-inf'), 0, j)
            self.dfs(heights, atlantic, float('-inf'), m - 1, j)
        
        # Find intersection
        for i in range(m):
            for j in range(n):
                if pacific[i][j] and atlantic[i][j]:
                    result.append([i, j])
        
        return result
    
    def dfs(self, heights: List[List[int]], visited: List[List[bool]], height: int, x: int, y: int):
        m = len(heights)
        n = len(heights[0])
        
        if x < 0 or x >= m or y < 0 or y >= n or visited[x][y] or heights[x][y] < height:
            return
        
        visited[x][y] = True
        
        self.dfs(heights, visited, heights[x][y], x - 1, y)
        self.dfs(heights, visited, heights[x][y], x + 1, y)
        self.dfs(heights, visited, heights[x][y], x, y - 1)
        self.dfs(heights, visited, heights[x][y], x, y + 1)
