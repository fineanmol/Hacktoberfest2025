class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void bfs(queue<pair<int,int>>& q, vector<vector<int>>& reach, vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || reach[nx][ny]) continue;
                if(heights[nx][ny] >= heights[x][y]) {
                    reach[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0)), atl(m, vector<int>(n, 0));
        queue<pair<int,int>> qp, qa;

        // Pacific borders (top row + left column)
        for(int i = 0; i < m; i++) {
            pac[i][0] = 1;
            qp.push({i, 0});
        }
        for(int j = 0; j < n; j++) {
            pac[0][j] = 1;
            qp.push({0, j});
        }

        // Atlantic borders (bottom row + right column)
        for(int i = 0; i < m; i++) {
            atl[i][n-1] = 1;
            qa.push({i, n-1});
        }
        for(int j = 0; j < n; j++) {
            atl[m-1][j] = 1;
            qa.push({m-1, j});
        }

        bfs(qp, pac, heights);
        bfs(qa, atl, heights);

        vector<vector<int>> res;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pac[i][j] && atl[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
