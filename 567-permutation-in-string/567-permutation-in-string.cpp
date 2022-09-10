class Solution {
public:
    
    bool checkInclusion (string &s1, string &s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        
        vector<int> s1_char(26, 0);
        vector<int> s2_char(26, 0);
        int len = s1.size();
        for (int i = 0; i < len; i++) {
            s1_char[s1[i] - 'a']++;
            s2_char[s2[i] - 'a']++;
        }
            
        if (s1_char == s2_char) {
            return true;
        }
        
        int k = len;
        int s2_len = s2.size();
        for (int i = 0; k < s2_len; i++, k++ ) {
            s2_char[s2[i] - 'a']--;
            s2_char[s2[k] - 'a']++;
             if (s1_char == s2_char) {
                return true;
            }   
        }
        return false;
    }
};