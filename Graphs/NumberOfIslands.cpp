/*
 * Problem: Number of Islands
 * 
 * Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water),
 * return the number of islands. An island is surrounded by water and is formed by 
 * connecting adjacent lands horizontally or vertically.
 * 
 * Example:
 * Input: grid = [
 *   ["1","1","1","1","0"],
 *   ["1","1","0","1","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","0","0","0"]
 * ]
 * Output: 1
 * 
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n) for DFS recursion stack in worst case
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    // Approach 1: DFS (Recursive)
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return islandCount;
    }
    
    // Approach 2: BFS (Iterative)
    int numIslandsBFS(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    bfs(grid, i, j);
                }
            }
        }
        
        return islandCount;
    }
    
    // Approach 3: DFS Iterative using stack
    int numIslandsDFSIterative(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfsIterative(grid, i, j);
                }
            }
        }
        
        return islandCount;
    }
    
    // Extension: Find the largest island area
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int area = calculateIslandArea(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
    
    // Extension: Find all island sizes
    vector<int> getAllIslandSizes(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return {};
        
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> islandSizes;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    int size = getIslandSize(grid, i, j);
                    islandSizes.push_back(size);
                }
            }
        }
        
        return islandSizes;
    }
    
    // Extension: Count closed islands (surrounded by water)
    int numClosedIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Mark all land cells connected to boundary as visited
        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 0) markBoundaryIsland(grid, i, 0);
            if (grid[i][cols-1] == 0) markBoundaryIsland(grid, i, cols-1);
        }
        
        for (int j = 0; j < cols; j++) {
            if (grid[0][j] == 0) markBoundaryIsland(grid, 0, j);
            if (grid[rows-1][j] == 0) markBoundaryIsland(grid, rows-1, j);
        }
        
        // Count remaining islands (closed islands)
        int closedIslands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    closedIslands++;
                    markBoundaryIsland(grid, i, j);
                }
            }
        }
        
        return closedIslands;
    }
    
    // Extension: Shortest bridge between two islands
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Find first island and mark it
        bool found = false;
        for (int i = 0; i < rows && !found; i++) {
            for (int j = 0; j < cols && !found; j++) {
                if (grid[i][j] == 1) {
                    markFirstIsland(grid, i, j);
                    found = true;
                }
            }
        }
        
        // BFS to find shortest path to second island
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        int steps = 0;
        vector<int> directions = {-1, 0, 1, 0, -1};
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int k = 0; k < size; k++) {
                auto [row, col] = q.front();
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int newRow = row + directions[d];
                    int newCol = col + directions[d+1];
                    
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                        if (grid[newRow][newCol] == 1) {
                            return steps;
                        } else if (grid[newRow][newCol] == 0) {
                            grid[newRow][newCol] = 2;
                            q.push({newRow, newCol});
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Base case: out of bounds or water/visited
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != '1') {
            return;
        }
        
        // Mark as visited
        grid[row][col] = '0';
        
        // Explore 4 directions
        dfs(grid, row - 1, col); // Up
        dfs(grid, row + 1, col); // Down
        dfs(grid, row, col - 1); // Left
        dfs(grid, row, col + 1); // Right
    }
    
    void bfs(vector<vector<char>>& grid, int startRow, int startCol) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        
        q.push({startRow, startCol});
        grid[startRow][startCol] = '0';
        
        vector<int> directions = {-1, 0, 1, 0, -1};
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            // Check 4 directions
            for (int d = 0; d < 4; d++) {
                int newRow = row + directions[d];
                int newCol = col + directions[d + 1];
                
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && 
                    grid[newRow][newCol] == '1') {
                    grid[newRow][newCol] = '0';
                    q.push({newRow, newCol});
                }
            }
        }
    }
    
    void dfsIterative(vector<vector<char>>& grid, int startRow, int startCol) {
        int rows = grid.size();
        int cols = grid[0].size();
        stack<pair<int, int>> st;
        
        st.push({startRow, startCol});
        grid[startRow][startCol] = '0';
        
        vector<int> directions = {-1, 0, 1, 0, -1};
        
        while (!st.empty()) {
            auto [row, col] = st.top();
            st.pop();
            
            // Check 4 directions
            for (int d = 0; d < 4; d++) {
                int newRow = row + directions[d];
                int newCol = col + directions[d + 1];
                
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && 
                    grid[newRow][newCol] == '1') {
                    grid[newRow][newCol] = '0';
                    st.push({newRow, newCol});
                }
            }
        }
    }
    
    int calculateIslandArea(vector<vector<int>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != 1) {
            return 0;
        }
        
        grid[row][col] = 0; // Mark as visited
        
        return 1 + calculateIslandArea(grid, row - 1, col) +
                   calculateIslandArea(grid, row + 1, col) +
                   calculateIslandArea(grid, row, col - 1) +
                   calculateIslandArea(grid, row, col + 1);
    }
    
    int getIslandSize(vector<vector<char>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != '1') {
            return 0;
        }
        
        grid[row][col] = '0'; // Mark as visited
        
        return 1 + getIslandSize(grid, row - 1, col) +
                   getIslandSize(grid, row + 1, col) +
                   getIslandSize(grid, row, col - 1) +
                   getIslandSize(grid, row, col + 1);
    }
    
    void markBoundaryIsland(vector<vector<int>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != 0) {
            return;
        }
        
        grid[row][col] = -1; // Mark as boundary connected
        
        markBoundaryIsland(grid, row - 1, col);
        markBoundaryIsland(grid, row + 1, col);
        markBoundaryIsland(grid, row, col - 1);
        markBoundaryIsland(grid, row, col + 1);
    }
    
    void markFirstIsland(vector<vector<int>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != 1) {
            return;
        }
        
        grid[row][col] = 2; // Mark first island
        
        markFirstIsland(grid, row - 1, col);
        markFirstIsland(grid, row + 1, col);
        markFirstIsland(grid, row, col - 1);
        markFirstIsland(grid, row, col + 1);
    }
    
public:
    // Helper function to print grid
    void printGrid(const vector<vector<char>>& grid) {
        cout << "Grid:" << endl;
        for (const auto& row : grid) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
    
    // Helper function to copy grid (since we modify it during traversal)
    vector<vector<char>> copyGrid(const vector<vector<char>>& original) {
        return original;
    }
    
    // Helper function to print vector
    void printVector(const vector<int>& vec, const string& label) {
        cout << label << ": [";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    Solution solution;
    
    cout << "=== Number of Islands Problem ===" << endl << endl;
    
    // Test case 1: Basic island counting
    cout << "Test Case 1: Basic Islands" << endl;
    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    
    solution.printGrid(grid1);
    
    auto grid1_copy1 = solution.copyGrid(grid1);
    auto grid1_copy2 = solution.copyGrid(grid1);
    auto grid1_copy3 = solution.copyGrid(grid1);
    
    cout << "DFS Recursive: " << solution.numIslands(grid1_copy1) << " islands" << endl;
    cout << "BFS: " << solution.numIslandsBFS(grid1_copy2) << " islands" << endl;
    cout << "DFS Iterative: " << solution.numIslandsDFSIterative(grid1_copy3) << " islands" << endl;
    
    auto grid1_copy4 = solution.copyGrid(grid1);
    vector<int> islandSizes = solution.getAllIslandSizes(grid1_copy4);
    solution.printVector(islandSizes, "Island sizes");
    cout << endl;
    
    // Test case 2: Multiple islands
    cout << "Test Case 2: Multiple Islands" << endl;
    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    
    solution.printGrid(grid2);
    
    auto grid2_copy = solution.copyGrid(grid2);
    cout << "Number of islands: " << solution.numIslands(grid2_copy) << endl;
    
    auto grid2_copy2 = solution.copyGrid(grid2);
    vector<int> sizes2 = solution.getAllIslandSizes(grid2_copy2);
    solution.printVector(sizes2, "Island sizes");
    cout << endl;
    
    // Test case 3: Single cells
    cout << "Test Case 3: Single Cell Islands" << endl;
    vector<vector<char>> grid3 = {
        {'1','0','1','1','1'},
        {'0','0','0','0','0'},
        {'1','0','0','1','0'},
        {'0','1','1','0','0'}
    };
    
    solution.printGrid(grid3);
    
    auto grid3_copy = solution.copyGrid(grid3);
    cout << "Number of islands: " << solution.numIslands(grid3_copy) << endl;
    cout << endl;
    
    // Test case 4: Extension - Max area of island
    cout << "Test Case 4: Max Area of Island" << endl;
    vector<vector<int>> grid4 = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    
    cout << "Max area of island: " << solution.maxAreaOfIsland(grid4) << endl;
    cout << endl;
    
    // Test case 5: Edge cases
    cout << "Test Case 5: Edge Cases" << endl;
    
    // Empty grid
    vector<vector<char>> emptyGrid = {};
    cout << "Empty grid: " << solution.numIslands(emptyGrid) << " islands" << endl;
    
    // All water
    vector<vector<char>> allWater = {
        {'0','0','0'},
        {'0','0','0'}
    };
    auto allWaterCopy = solution.copyGrid(allWater);
    cout << "All water: " << solution.numIslands(allWaterCopy) << " islands" << endl;
    
    // All land
    vector<vector<char>> allLand = {
        {'1','1','1'},
        {'1','1','1'}
    };
    auto allLandCopy = solution.copyGrid(allLand);
    cout << "All land: " << solution.numIslands(allLandCopy) << " islands" << endl;
    
    return 0;
}