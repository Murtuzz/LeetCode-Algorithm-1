class Solution {
public:
    int m_b_s (vector<int>& nums, int low, int high) {
        int mid = (low + high) / 2;
        int len = nums.size();
        if ((mid + 1) >= len) {
            if (nums[mid] > nums[mid - 1]) return mid;
            return m_b_s (nums, low, mid - 1);
        } else if ((mid - 1) < 0) {
            if (nums[mid] > nums[mid + 1]) return mid;
            return m_b_s (nums, mid + 1, high);
        } else if (nums[mid] > nums[mid + 1] &&  nums[mid] > nums[mid - 1]) {
            return mid;
        } else if (nums[mid + 1] > nums[mid]) {
            return m_b_s (nums, mid + 1, high);
        }
        return m_b_s (nums, low, mid - 1);
    }
    
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 0;
        return m_b_s (nums, 0, len - 1);
    }
};