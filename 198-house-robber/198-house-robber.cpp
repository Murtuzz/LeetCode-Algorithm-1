class Solution {
public:
    int rob(vector<int>& nums) {
        int first =  nums[0];
        int len = nums.size();
        if (len == 1) {
            return first;
        }
        
        int second = max(first, nums[1]);
        int maxMoney = second;
        
        for (int i = 2; i < len; i++) {
            maxMoney = max(second, first + nums[i]);
            first = second;
            second = maxMoney;
        }
        
        return maxMoney;
    }
};