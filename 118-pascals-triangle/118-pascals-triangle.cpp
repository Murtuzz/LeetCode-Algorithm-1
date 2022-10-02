class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p_tr;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 0);
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row[j] = 1;
                    continue;
                }
                row[j] = p_tr[i - 1][j - 1] + p_tr[i - 1][j];
            }
            p_tr.push_back(row);
        }
        return p_tr;
    }
};

