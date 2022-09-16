class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int first = nums[0];
        int second = max(nums[1], first);
        int current = second;
        for (int i = 2; i < size; i++) {
            current = max(first + nums[i], second);
            first = second;
            second = current;
        }
        return current;
    }
};