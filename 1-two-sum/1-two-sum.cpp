class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int len = nums.size();
        vector<int> rst(2);
        
        for (int i = 0; i < len; i++) {
            int diff = target - nums[i];
            auto itr = mp.find(diff);
            
            if ( itr != mp.end()) {
                rst[0] = itr->second;
                rst[1]= i;
                break;
            }
            mp[nums[i]] = i;
        }
        return rst;
    }
};