class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort (nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 2; i++ ) {
            int j = i + 1, k = len - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (!sum) {
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++, k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        vector <vector<int>> rst;
        for (auto a : ans) rst.push_back(a);
        return rst;
    }
};