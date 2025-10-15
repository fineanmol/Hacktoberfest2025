// Word Search

// Problem: Find if a word exists in a 2D board.

// Solution:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int index, int i, int j, vector<vector<bool>>& visited) {
        if (index == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index])
            return false;
        visited[i][j] = true;
        bool found = dfs(board, word, index + 1, i + 1, j, visited) ||
                     dfs(board, word, index + 1, i - 1, j, visited) ||
                     dfs(board, word, index + 1, i, j + 1, visited) ||
                     dfs(board, word, index + 1, i, j - 1, visited);
        visited[i][j] = false;
        return found;
    }
};