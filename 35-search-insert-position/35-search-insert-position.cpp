class Solution {
public:
    int targetIndex(vector<int>& arr, int &target, long low, long high) {
        if( low <= high) {
            long mid = (low + high) / 2;
            if (arr[mid] == target){
                return mid;
            }
            else if (arr[mid] > target) {
                return targetIndex(arr, target, low, (mid - 1));
            } else {
                return targetIndex(arr, target, (mid + 1), high);
            }
        } else {
            return low;
        }
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return targetIndex(nums, target, 0, (nums.size() - 1));
    }
};