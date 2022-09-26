class Solution {
public:
//     int jump(vector<int>& nums, vector<int>& store_jump, int indx) {
//         int len = nums.size() - 1;
//         if (len <= indx) {
//             return 0;
//         }
        
//         if (store_jump[indx] != INT_MAX) {
//             return store_jump[indx];
//         }
        
//         for (int i = nums[indx]; i > 0; i--) {
//             store_jump[i + indx] = min(jump(nums, store_jump, indx + i) + 1, store_jump[i]);
//         }
//     }
    
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> store_jump(len, INT_MAX);
        
        for (int i = len - 2; i >= 0; i--) {
            for (int j = nums[i]; j > 0; j--) {
                if (i + j >= len - 1) {
                    store_jump[i] = 1;
                    break;
                }
                
                if (store_jump[i + j] != INT_MAX) {
                    store_jump[i] = min (store_jump[i + j] + 1, store_jump[i]);
                }
            }
        }
        return store_jump[0] == INT_MAX ? 0 : store_jump[0];
    }
};
