class Solution {
public:
    int square(int num){
        return (num * num);
    }
    
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> rslt;
        int neg = -1, pos = -1;
        int len = nums.size() - 1;
        
        for (int i = 0; i <= len; i++) {
            if (nums[i] >= 0 ) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            neg = len;
        } else {
            neg = pos -1;
        }
        
        while ((neg >= 0) && (pos <= len) && (pos != -1)) {
            if(abs(nums[neg]) > nums[pos]){
                rslt.push_back(square(nums[pos++]));
            } else {
                rslt.push_back(square(nums[neg--]));
            }
        }
        
        while (neg >= 0){
            rslt.push_back(square(nums[neg--]));
        }
        
        while (pos <= len && pos != -1) {
            rslt.push_back(square(nums[pos++]));
        }
        
        return rslt;
    }
};