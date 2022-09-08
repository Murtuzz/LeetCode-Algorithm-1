class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int j = 0;
        for (int i = 0; i < len; i++ ) {
            if (s[i] == ' ') {
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            } else if (i == len-1) {
                reverse(s.begin() + j, s.begin() + (i + 1));
            }
        }
        return s;
    }
};
// reverse()