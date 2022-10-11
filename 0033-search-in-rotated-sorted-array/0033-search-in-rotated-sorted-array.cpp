class Solution {
public:
    
    int m_b_s (vector<int>& nums, long low, long high) {
        
        int len = nums.size();
        long mid = (low + high) / 2;
        long m_left = (len + mid - 1) % len;
        long m_right = (mid + 1) % len;
        
        if (nums[mid] < nums[m_left] && nums[mid] < nums[m_right]) {
            return mid;
        } else if (nums[low] <= nums[mid] && nums[mid] < nums[high] || nums[low] > nums[mid]) {
            return m_b_s (nums, low, mid - 1);
        }

        return m_b_s (nums, mid + 1, high);
    }
    
    int b_s (vector<int>& nums, long low, long high, int& target) {
        if (low <= high) {
            long mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                return b_s (nums, low, mid - 1, target);
            }
            return b_s (nums, mid + 1, high, target);
        }
        return -1;
    }
        
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 1 ) {
            if (nums[0] != target) {
                return -1;
            } else {
                return 0;
            }
        }
        
        int r_p =  m_b_s (nums, 0, len - 1);
        if (r_p == 0) {
            return b_s (nums, 0, len - 1, target);
        }
        if (nums[0] <= target && target <= nums[r_p - 1]) {
            return b_s (nums, 0, r_p - 1, target);
        } else if (nums[r_p] <= target && target <= nums[len - 1]) {
            return b_s (nums, r_p, len - 1, target);
        }
        return -1;
    }
};