class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> permutations;
        int len  = s.size();
        vector <int> index;
        int count = 0;
        for (int i = 0; i < len; i++) {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                count++;
                index.push_back(i);
            }
        }
        int permutation = pow(2, count);
        
        for (int i = 0; i < permutation; i++) {
            int j = i;
            string c_s = s;
            int count = 0;
            while (j > 0) {
                if (j&1) {
                    if (s[index[count]] >= 'A' && s[index[count]] <= 'Z') {
                        c_s[index[count]] = c_s[index[count]] + ('a' - 'A');
                    } else {
                        c_s[index[count]] = c_s[index[count]] - ('a' - 'A');
                    }
                }
                count++;
                j = j >> 1;
            }
            permutations.push_back(c_s);
        }
        return permutations;
    }
};