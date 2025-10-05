#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void f(vector<vector<int>>& maze, int n, string &path, vector<vector<bool>>& vis, int row, int col) {
    // Base case: reached destination
    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    // Direction vectors: D, L, R, U
    int dRow[] = {1, 0, 0, -1};
    int dCol[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'};

    for (int i = 0; i < 4; i++) {
        int newRow = row + dRow[i];
        int newCol = col + dCol[i];

        // Check bounds and if cell is open and not visited
        if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < n &&
            !vis[newRow][newCol] && maze[newRow][newCol] == 1) {
            
            vis[newRow][newCol] = true;
            path.push_back(dir[i]);
            
            f(maze, n, path, vis, newRow, newCol);
            
            // Backtrack
            path.pop_back();
            vis[newRow][newCol] = false;
        }
    }
}

vector<string> ratInMaze(vector<vector<int>>& maze) {
    ans.clear();
    int n = maze.size();
    if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0) return ans;

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    string path = "";

    vis[0][0] = true;
    f(maze, n, path, vis, 0, 0);

    return ans;
}
