class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        
        int len2 = nums2.size();
        for (int i = 0; i < len2; i++) {
            mp[nums2[i]] = i; 
        }
        
        int len1 = nums1.size();
        vector<int> ans(len1, -1);
        for (int i = 0; i < len1; i++) {
            int num = nums1[i];
            int indx2 = mp[num];
            for (int j = indx2; j < len2; j++) {
                if (num < nums2[j]) {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};

/*

    Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
    Output: [-1,3,-1]
    
    Input: nums1 = [2,4], nums2 = [1,2,3,4]
    Output: [3,-1]
    
*/