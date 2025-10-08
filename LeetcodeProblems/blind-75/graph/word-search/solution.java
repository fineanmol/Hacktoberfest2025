// Word Search - LeetCode #79

class Solution {
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    private boolean dfs(char[][] board, String word, int i, int j, int index) {
        if (index == word.length()) return true;
        
        int m = board.length;
        int n = board[0].length;
        
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word.charAt(index)) return false;
        
        char temp = board[i][j];
        board[i][j] = '#'; // Mark visited
        
        boolean found = dfs(board, word, i - 1, j, index + 1) ||
                        dfs(board, word, i + 1, j, index + 1) ||
                        dfs(board, word, i, j - 1, index + 1) ||
                        dfs(board, word, i, j + 1, index + 1);
        
        board[i][j] = temp; // Backtrack
        
        return found;
    }
}
