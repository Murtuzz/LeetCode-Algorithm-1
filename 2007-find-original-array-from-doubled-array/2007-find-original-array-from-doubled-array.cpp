class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int len = changed.size();
        
        if ( len&1 ) {
            return {};
        }
        
        sort(changed.begin(), changed.end());
        
        unordered_map<int,int> store;
        for ( int i = 0; i < len; i++) {
            store[changed[i]]++;
        }
        
        vector<int> original;
        for ( int i = 0; i < len; i++) {
            if (store[changed[i]] && store[changed[i] * 2]) {
                original.push_back(changed[i]);
                store[changed[i] * 2]--;
                store[changed[i]]--;
            } else if (store[changed[i]] && !store[changed[i] * 2]) {
                return {};
            }
        }
        return original;
    }
};