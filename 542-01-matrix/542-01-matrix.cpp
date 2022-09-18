class Solution {
public:
    
    bool is_valid (int i, int j, int& lenRow, int& lenCol, vector<vector<bool>>& visited) {
        if ( i >= 0 && j >= 0 && i < lenRow && j < lenCol && !visited[i][j]) {
            visited[i][j] = true;
            return true; 
        }
        return false;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int lenRow = mat.size();
        int lenCol = mat[0].size();
        vector<vector<bool>> visited(lenRow, vector<bool>(lenCol, false));

        queue <pair<int,int>>  q;
        for (int i = 0; i < lenRow; i++) {
            for (int j = 0; j < lenCol; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;
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
                if (is_valid (i + 1, j, lenRow, lenCol, visited)) {
                    q.push ({i + 1, j});
                    mat[i + 1][j] = mat[i][j] + 1;
                }
                
                if (is_valid (i - 1, j, lenRow, lenCol, visited)) {
                    q.push ({i - 1, j});
                    mat[i - 1][j] = mat[i][j] + 1; 
                }
                
                if (is_valid (i, j + 1, lenRow, lenCol, visited)) {
                    q.push ({i, j + 1});
                    mat[i][j + 1] = mat[i][j] + 1; 
                }
                
                if (is_valid (i, j - 1, lenRow, lenCol, visited)) {
                    q.push ({i, j - 1});
                    mat[i][j - 1] = mat[i][j] + 1; 
                }
            }
        }
        
        return mat;
    }
};
