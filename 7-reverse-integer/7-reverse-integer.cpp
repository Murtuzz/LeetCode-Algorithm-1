class Solution {
public:
    int reverse(int x) {
        long rslt = 0; 
        bool flag = false;
        long value = x;
        if(x < 0){
            flag = true;
            value *= -1;
        }
        while(value > 0) {
            rslt *= 10;
            rslt += value%10;
            value /= 10;
            if(rslt < 0){
                return 0;
            }
        }
        long max_int = INT_MAX;
        if(flag){
            if(rslt > (max_int + 1))
                return 0;
            return (rslt * -1);   
        }
        
        if(rslt > max_int)
            return 0;
        return rslt;
        
    }
};