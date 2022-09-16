class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        vector <int> mem(size + 1, 0);
        mem[0] = nums[0];
        mem[1] = max(nums[1], mem[0]);
        for (int i = 2; i < size; i++) {
            mem[i] = max(mem[i - 2] + nums[i], mem[i - 1]);          
        }
        return mem[size - 1];
    }
};