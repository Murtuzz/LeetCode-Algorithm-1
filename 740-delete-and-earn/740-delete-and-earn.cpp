class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = INT_MIN;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            maxNum = max(maxNum, nums[i]);
        }
        
        
        vector<int>numsCount (maxNum + 1);
        for (int i = 0; i < len; i++) {
            numsCount[nums[i]]++;
        }
        
        if (maxNum == 1) {
            return  numsCount[1];
        } else if (maxNum == 2) {
            return  max(numsCount[1], (numsCount[2] * 2));
        }
        
        numsCount[1] = numsCount[1];
        numsCount[2] = max(2 * numsCount[2], numsCount[1]) ;
        for (int i = 3; i <= maxNum; i++ ) {
            numsCount[i] = max ((numsCount[i] * i) + numsCount[i - 2], numsCount[i - 1]);
        }

        return numsCount[maxNum];
     }
};