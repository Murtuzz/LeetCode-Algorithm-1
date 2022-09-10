class Solution {
public:
    vector<vector<int>> subsets_arr;
    void subsets (vector<int>& nums, vector<int> subset_arr, int index) {
        subsets_arr.push_back(subset_arr);
        for (int i = index; i < nums.size(); i++) {
            subset_arr.push_back(nums[i]);
            subsets(nums, subset_arr, i + 1);
            subset_arr.pop_back();
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> empty_vec;
        subsets(nums, empty_vec, 0);
        return subsets_arr;
    }
};