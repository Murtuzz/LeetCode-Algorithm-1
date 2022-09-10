class Solution {
public:
    bool checkThePermutation (string s2, vector<int> s1_char) {
        vector<int> s2_char(26, 0);
        int len = s2.size();
        for (int i = 0; i < len; i++) {
            s2_char[s2[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (s1_char[i] != s2_char[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion (string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        
        vector<int> s1_char(26, 0);
        int len = s1.size();
        for (int i = 0; i < len; i++) {
            s1_char[s1[i] - 'a']++;
        }
        
        int s2_len = s2.size();
        for (int i = 0; i <= (s2_len - len); i++ ) {
            if (checkThePermutation(s2.substr (i, len), s1_char)) {
               return true; 
            }
        }
        return false;
    }
};