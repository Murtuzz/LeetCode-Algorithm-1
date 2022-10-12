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
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.insert(temp);
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