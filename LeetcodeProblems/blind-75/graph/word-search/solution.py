# Word Search - LeetCode #79

from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        
        for i in range(m):
            for j in range(n):
                if self.dfs(board, word, i, j, 0):
                    return True
        
        return False
    
    def dfs(self, board: List[List[str]], word: str, i: int, j: int, index: int) -> bool:
        if index == len(word):
            return True
        
        m = len(board)
        n = len(board[0])
        
        if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[index]:
            return False
        
        temp = board[i][j]
        board[i][j] = '#'  # Visited
        
        found = (self.dfs(board, word, i - 1, j, index + 1) or
                 self.dfs(board, word, i + 1, j, index + 1) or
                 self.dfs(board, word, i, j - 1, index + 1) or
                 self.dfs(board, word, i, j + 1, index + 1))
        
        board[i][j] = temp  # Backtrack
        
        return found
