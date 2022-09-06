class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        // Complete Reverse         
        reverse(nums.begin(), nums.end());
        // Reverse from kth element to end
        reverse(nums.begin() + k, nums.end());
        // Reverse starting k element         
        reverse(nums.begin(), nums.begin() + k);
    }
};