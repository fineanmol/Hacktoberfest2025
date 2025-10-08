# Set Matrix Zeroes - LeetCode #73

from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        if not matrix or not matrix[0]:
            return
        
        m = len(matrix)
        n = len(matrix[0])
        first_row_zero = False
        first_col_zero = False
        
        # Check first row
        for j in range(n):
            if matrix[0][j] == 0:
                first_row_zero = True
                break
        
        # Check first col
        for i in range(m):
            if matrix[i][0] == 0:
                first_col_zero = True
                break
        
        # Mark
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        
        # Set zeros
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        
        # Set first row
        if first_row_zero:
            for j in range(n):
                matrix[0][j] = 0
        
        # Set first col
        if first_col_zero:
            for i in range(m):
                matrix[i][0] = 0
