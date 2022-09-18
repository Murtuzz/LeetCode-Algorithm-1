class Solution {
public:
    
    void generate_permutation (vector<int> nums, vector<vector<int>> &permutations, int start) {
        if (start == nums.size() - 1) {
            permutations.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap (nums[start], nums[i]);
            generate_permutation (nums, permutations, start + 1);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        int len = nums.size();
        generate_permutation (nums, permutations, 0);
        
        return permutations;
    }
};