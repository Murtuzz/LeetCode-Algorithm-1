class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int len = pref.size();
        for (int i = len - 1; i > 0; i--) {
            pref[i] = pref[i] ^ pref[i-1];
        }
        return pref;
    }
};