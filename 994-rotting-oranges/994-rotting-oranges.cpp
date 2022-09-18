class Solution {
public:
    bool check_condition_and_rotten_it (int i, int j, int &len_row, int &len_col, vector<vector<int>>& grid) {
        if (i >= 0 && j >= 0 && i < len_row && j < len_col && grid[i][j] == 1) {
            grid[i][j] = 2;
            return true;
        }
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int len_row = grid.size();
        int len_col = grid[0].size();
        int count = 0;
        queue <pair<int,int>> q;
        
        for (int i = 0; i < len_row; i++) {
            for (int j = 0; j < len_col; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(check_condition_and_rotten_it (i+1, j, len_row, len_col, grid)) {
                    q.push({i+1,j});
                }

                if(check_condition_and_rotten_it (i-1, j, len_row, len_col, grid)) {
                    q.push({i-1,j});
                }

                if(check_condition_and_rotten_it (i, j+1, len_row, len_col, grid)) {
                    q.push({i,j+1});
                }

                if(check_condition_and_rotten_it (i, j-1, len_row, len_col, grid)) {
                    q.push({i,j-1});
                }
            }
            if (!q.empty()) {
                count++;
            }
        }
        
        for (int i = 0; i < len_row; i++) {
            for (int j = 0; j < len_col; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return count;
    }
};

// 1        2      2       1       1
// [2,1,1] [2,2,1] [2,2,2] [2,2,2] [2,2,2]
// [1,1,0] [2,1,0] [2,2,0] [2,2,0] [2,2,0]
// [0,1,1] [0,1,1] [0,1,1] [0,2,1] [0,2,2]