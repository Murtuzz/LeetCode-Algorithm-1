class Solution {
public:
    int get_reminder (int num, int div) { 
        while (num % div == 0) num = num/div;
        return num;
    }
    bool isUgly(int n) {
        bool flag = true;
        if (n < 1) flag = false;
        else if (n > 6) {
            if (n % 2 == 0){
                n = get_reminder (n, 2);
            }
            if (n % 5 == 0){
                n = get_reminder (n, 5);
            }
            if (n % 3 == 0){
                n = get_reminder (n, 3);
            }
            if (n != 1) flag = false;
        }
        return flag;
    }
};