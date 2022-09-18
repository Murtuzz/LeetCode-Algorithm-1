class Solution {
public:
//     void dfs(vector<vector<int>>& mat, int i, int j, vector<vector<bool>> visited, int count, int &minimum, vector<vector<int>> &mem) {
//         int lenRow = mat.size();
//         int lenCol = mat[0].size();
//         if ( i < 0 || j < 0 || i == lenRow || j == lenCol || visited[i][j]) {
//             return;
//         }
        
//         if (mem[i][j] != 0) {
//             count += mem[i][j];
//             minimum = min ( minimum, count);
//             return;
//         }
//         if (mat[i][j] == 0) {
//             minimum = min ( minimum, count);
//             return;
//         }
//         visited[i][j] = true;
//         count++;
//         dfs(mat, i-1, j, visited, count, minimum, mem);
//         dfs(mat, i+1, j, visited, count, minimum, mem);
//         dfs(mat, i, j+1, visited, count, minimum, mem);
//         dfs(mat, i, j-1, visited, count, minimum, mem);
//     }
    
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int lenRow = mat.size();
//         int lenCol = mat[0].size();
//         vector<vector<int>> newMat(lenRow, vector<int>(lenCol));
//         vector<vector<bool>> visited(lenRow, vector<bool>(lenCol));
//         vector<vector<int>> mem(lenRow, vector<int>(lenCol));
        
//         for (int i = 0; i < lenRow; i++) {
//             for (int j = 0; j < lenCol; j++) {
//                 if (mat[i][j] == 0) {
//                     newMat[i][j] = 0;
//                 } else {
//                     int count = 0;
//                     int minimum = INT_MAX;
//                     dfs (mat, i, j, visited, count, minimum, mem);
//                     newMat[i][j] = minimum;
//                     mem[i][j] = newMat[i][j];
//                 }
//             }
//         }
//         return newMat;
//     }
    
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
        vector<vector<int>> newMat(lenRow, vector<int>(lenCol));
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
         // [0,0,1]    [0,0,1]    [0,0,1]    
         // [0,1,0]    [0,1,0]    [0,1,0]    
         // [1,1,1]    [1,,1]     [1,2,1]
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if (is_valid (i + 1, j, lenRow, lenCol, visited)) {
                    q.push ({i + 1, j});
                    newMat[i + 1][j] = newMat[i][j] + 1;
                }
                
                if (is_valid (i - 1, j, lenRow, lenCol, visited)) {
                    q.push ({i - 1, j});
                    newMat[i - 1][j] = newMat[i][j] + 1; 
                }
                
                if (is_valid (i, j + 1, lenRow, lenCol, visited)) {
                    q.push ({i, j + 1});
                    newMat[i][j + 1] = newMat[i][j] + 1; 
                }
                
                if (is_valid (i, j - 1, lenRow, lenCol, visited)) {
                    q.push ({i, j - 1});
                    newMat[i][j - 1] = newMat[i][j] + 1; 
                }
            }
        }
        
        return newMat;
    }
};
