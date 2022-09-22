class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        if (len == 2) {
            return max(nums[0], nums[1]);
        }
        if (len == 3) {
            return (nums[0] > nums[1] && nums[0] > nums[2]) ? nums[0] : (nums[1] > nums[2]) ? nums[1] : nums[2]; 
        }
        
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        int maxMoney = second; 
        for (int i = 2; i < len - 1; i++) {
            maxMoney = max(second, first + nums[i]);
            first = second;
            second = maxMoney;
        }
        
        first = nums[1];
        second = max(nums[2], nums[1]);
        int maxMoney2 = second; 
        for (int i = 3; i < len; i++) {
            maxMoney2 = max(second, first + nums[i]);
            first = second;
            second = maxMoney2;
        }
        return max(maxMoney, maxMoney2);
    }
};
