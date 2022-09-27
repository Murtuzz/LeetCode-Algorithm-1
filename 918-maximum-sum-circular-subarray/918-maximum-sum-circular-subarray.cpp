class Solution {

    public:
    
    int maxSubarraySumCircular(vector<int>& nums) {

        int len = nums.size();
        int prev = nums[0];
        int maximum = nums[0];

        for (int i = 1; i < len; i++) {
            if (prev > 0 && (prev + nums[i]) > 0) {
                prev += nums[i];
            } else {
                prev = nums[i];
            }
            maximum = max(maximum, prev);
        }
        int sum_nums = 0;
        for (int i = 0; i < len; i++) {
            sum_nums += nums[i];
            nums[i] *= -1;
        }
        prev = nums[0];
        int maximum_2 = nums[0];
        
        for (int i = 1; i < len; i++) {
            if (prev > 0 && (prev + nums[i]) > 0) {
                prev += nums[i];
            } else {
                prev = nums[i];
            }
            maximum_2 = max(maximum_2, prev);
        }
        maximum_2 += sum_nums;
        if (maximum_2 <= 0) {
            return maximum;
        }
        return max(maximum, maximum_2);
    }
};

// [-1,-2,40,-5,3,1,-100,-50]
// 1,2,-40,5,-3,-1,100,50
//     -108 + 151 