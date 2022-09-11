class Solution {
public:
    void getAreaCount(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int& count) {
        int rowLen = grid.size();
        int colLen = grid[0].size();
        if (i < 0 || j < 0 || i == rowLen || j == colLen || !grid[i][j] || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        count++;
        getAreaCount(grid, i+1, j, visited, count);
        getAreaCount(grid, i-1, j, visited, count);
        getAreaCount(grid, i, j+1, visited, count);
        getAreaCount(grid, i, j-1, visited, count);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();
        int maxArea = 0;
        vector<vector<bool>>visited (rowLen, vector<bool>(colLen, false));
        for ( int i = 0; i < rowLen; i++) {
            for ( int j = 0; j < colLen; j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    getAreaCount(grid, i, j, visited, count);
                    maxArea = max(count, maxArea);
                }
            }
        }
        return maxArea;
    }
};