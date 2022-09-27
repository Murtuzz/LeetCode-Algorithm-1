class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int>store_sum(len + 1, 0); 
        int maximum = nums[0];
        store_sum[0] = nums[0];
        
        for (int i = 1; i < len; i++) {
            if (store_sum[i - 1] > 0 && store_sum[i - 1] + nums[i] > 0) {
                store_sum[i] = store_sum[i - 1] + nums[i];
            } else {
                store_sum[i] = nums[i];
            }
            maximum = max (maximum, store_sum[i]);
        }
        return maximum;
    }
};