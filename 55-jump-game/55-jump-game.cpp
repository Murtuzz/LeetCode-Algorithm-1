class Solution {
public:
    void canJump(vector<int>& nums, vector<int> &store_path, int indx) {
        int len = nums.size() - 1;
        if (len <= indx) {
            store_path[len] = 1;
            return;
        }
        
        if (store_path[len] == 1 || store_path[indx] == 0) {
            return ;
        }
        
        if (nums[indx] == 0) {
            return;
        }
        
        for (int i = nums[indx]; i > 0; i--) {
            if (store_path[len] == 1) {
                return ;
            }   
            canJump(nums, store_path, indx + i);
        }
            store_path[indx] = 0;
    }

    
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<int> store_path(len, -1);
        canJump(nums, store_path, 0);
        return (store_path[len - 1] == 1);
    }
};


