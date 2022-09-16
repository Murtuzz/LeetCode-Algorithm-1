class Solution {
public:
    void combination (int start, vector<int> curr_comb, vector<vector<int>> &combinations,int &k, int &n) {
        int len = curr_comb.size();
        if (len == k) {
            combinations.push_back(curr_comb);
            return;
        }
        
        for (int i = start; i <= n; i++) {
            curr_comb.push_back(i);
            combination(i+1, curr_comb, combinations, k, n);
            curr_comb.pop_back();
        }
    }
    
    vector<vector<int>> combine(int &n, int &k) {
        vector<vector<int>> combinations;
        combination(1, {}, combinations, k, n);
        return combinations;
    }
};