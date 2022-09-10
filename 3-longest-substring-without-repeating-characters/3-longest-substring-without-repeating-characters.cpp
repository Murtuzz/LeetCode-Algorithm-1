class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>chrIndexArr(256,-1);
        int maxWRS = 0;
        int start_index = 0;
        for ( int i = 0; i < s.size(); i++) {
            if ( chrIndexArr[s[i]] >= start_index) {
                start_index = chrIndexArr[s[i]] + 1;
            }
            maxWRS = max(maxWRS, (i - start_index) + 1 );
            chrIndexArr[s[i]] = i;        
        }
        return maxWRS;
    }
};