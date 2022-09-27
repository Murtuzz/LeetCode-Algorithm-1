class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int maximum = nums[0];
        int prev = nums[0];
        
        for (int i = 1; i < len; i++) {
            if (prev > 0 && prev + nums[i] > 0) {
                prev += nums[i];
            } else {
                prev = nums[i];
            }
            maximum = max (maximum, prev);
        }
        return maximum;
    }
};