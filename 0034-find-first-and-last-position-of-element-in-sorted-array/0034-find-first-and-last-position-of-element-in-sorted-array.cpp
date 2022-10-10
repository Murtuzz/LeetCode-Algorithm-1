class Solution {
public:
    vector<int> modified_binary_search(vector<int>& nums, int &target, long low, long high) {
        if ( low <= high) {
            long mid = (low + high) / 2;
            if (nums[mid] == target) {
                int first = mid; 
                while (first >= 0 && nums[first] == target) {
                    first--;
                }
                first++;
                
                int last = mid;
                int len = nums.size();
                while (last < len && nums[last] == target) {
                    last++;
                }
                last--;
                return {first, last};
            } else if (nums[mid] > target ) {
                return modified_binary_search(nums, target, low, mid - 1);
            } else {
                return modified_binary_search(nums, target, mid + 1, high);
            }
        }
        return {-1, -1};
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        return modified_binary_search(nums, target, 0, len - 1);        
    }
};