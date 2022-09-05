class Solution {
public:
    int binary_search(vector<int>& arr, int &target, int low, int high) {
        
        if (low <= high) {
            long mid = (low + high) / 2;

            if(arr[mid] == target)
                return mid;
            else if(arr[mid] > target)
                return binary_search(arr, target, low, (mid-1));
            else
                return binary_search(arr, target, (mid+1), high);   
        }
        else
            return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, (nums.size() - 1));
    }
};
