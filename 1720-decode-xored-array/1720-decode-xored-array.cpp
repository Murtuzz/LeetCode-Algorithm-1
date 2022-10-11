class Solution {
    
public:
    // *** need this constructor to boost the speed ***  
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }

    vector<int> decode(vector<int>& encoded, int first) {
        int len = encoded.size();
        vector<int> ans(len + 1);
        ans[0] = first;
        for (int i = 0; i < len; i++) {
            ans[i + 1] = ans[i] ^ encoded[i];
        }
        return ans;
    }
};