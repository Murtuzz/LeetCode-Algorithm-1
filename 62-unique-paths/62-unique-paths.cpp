class Solution {
public:
    int uniquePaths (int m, int n, vector<vector<int>> &mem) {
        
        if (m < 0 || n < 0){
            return 0;
        } else if (m == 1 && n == 1) {
            return 1;
        }
        if (mem[m][n] != 0) {
            return mem[m][n];
        }
        mem[m][n] = uniquePaths(m-1, n, mem) + uniquePaths(m, n-1, mem);
        return  mem[m][n];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem((m+1), vector<int>(n+1));
        if (m < 0 || n < 0){
            return 0;
        } else if (m == 1 && n == 1) {
            return 1;
        }
        uniquePaths(m, n, mem);
        return mem[m][n];
    }
};