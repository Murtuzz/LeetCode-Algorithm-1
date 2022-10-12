class Solution {
public:
    int m_b_s_r (vector<vector<int>>& matrix, int &target, int low, int high) {
        if (low <= high) {
            int mid = (low + high) / 2;
            int r_e_i = matrix[mid].size() - 1;
            
            if (matrix[mid][0] <= target && target <= matrix[mid][r_e_i]) return mid;
            else if (matrix[mid][0] > target) return m_b_s_r (matrix, target, low, mid - 1);
            else return m_b_s_r (matrix, target, mid + 1, high);
        }
        return -1;
    }
    
    bool b_s (vector<vector<int>>& matrix, int &target, int low, int high, int &r_i) {
        if (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[r_i][mid] == target) return true;
            else if (matrix[r_i][mid] > target) return b_s (matrix, target, low, mid - 1, r_i);
            else return b_s (matrix, target, mid + 1, high, r_i);
        }
        return false;
    }
    
    
    bool searchMatrix (vector<vector<int>>& matrix, int &target) {
        int len = matrix.size();
        int row = m_b_s_r (matrix, target, 0, len - 1);
        if (row == -1) return false;
        int r_len = matrix[row].size();
        return b_s (matrix, target, 0, r_len - 1, row);
    }
};