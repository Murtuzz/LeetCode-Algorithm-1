class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort (nums.begin(), nums.end());
        int len = nums.size();
        int i, j, k;
        int sum;
        vector<int> temp(3);
        for (i = 0; i < len - 2; i++ ) {
            j = i + 1, k = len - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];
                    ans.insert(temp);
                    j++, k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        vector<vector<int>> rst;
        for (auto x : ans) {
            rst.push_back(x);
        }
        return rst;
    }
};