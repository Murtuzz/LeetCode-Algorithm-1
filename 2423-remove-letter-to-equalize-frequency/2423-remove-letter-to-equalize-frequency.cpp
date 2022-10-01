class Solution {
public:
   
    bool equalFrequency(string word) {
       
        vector <int> v(26,0);
        int first = -1;
        int second = -1;
       
        for(int i = 0; i < word.size(); i++) {
            v[ word[ i ] - 'a' ]++;
        }
     
        int f_c = 0;
        int s_c = 0;
        int _c = 0;
        for(int i = 0; i < 26; i++) {
            if (v[ i ] != 0) {
                _c++;
            }
            
            if(v[ i ] == 0){
                continue;
            } else if(f_c > 0 && s_c > 0) {
                return false;
            } else if(v[ i ] == first) {
                f_c++;
                continue;
            } else if( v[ i ] == second) {
                s_c++;
                continue;
            } else if(v[ i ] != 0 && (first == -1 || second == -1)) {
                if(first != -1 ) {
                    second = v[i];
                }
                else {
                   first = v[i];
                }
            } else {
                return false;
            }
        }
        if (first == 1 && _c > 1 && second == -1) {
            return true;
        }
        if (_c == 1 && first > 1) {
            return true;
        } else if(f_c > 0 && s_c > 0) {
            return false;
        } else if(first == -1 || second == -1) {
            return false;
        } else if(f_c > s_c) {
            if (second == 1 || second - first == 1) {
                return true;
            } else {
                return false;
            }
        } else if (f_c < s_c) {
             if ((first == 1 || first - second == 1)) {
                return true;
            } else {
                return false;
            }  
        } 
        return true;
    }
};