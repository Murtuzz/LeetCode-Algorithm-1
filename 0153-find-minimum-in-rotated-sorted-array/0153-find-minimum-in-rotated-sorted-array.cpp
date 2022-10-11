class Solution {
public:
    
    int m_b_s (vector<int>& nums, long low, long high) {
        
        int len = nums.size();
        long mid = (low + high) / 2;
        long m_left = (len + mid - 1) % len;
        long m_right = (mid + 1) % len;
        
        if (nums[mid] < nums[m_left] && nums[mid] < nums[m_right]) {
            return nums[mid];
        } else if (nums[low] < nums[mid] && nums[mid] < nums[high] || nums[low] > nums[mid]) {
            return m_b_s (nums, low, mid - 1);
        }
        return m_b_s (nums, mid + 1, high);
    }
    
    int findMin (vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        return m_b_s (nums, 0, len - 1);
    }
};