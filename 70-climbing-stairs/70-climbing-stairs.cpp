class Solution {
public:
    int climbStairs(int n, vector<int> &mem) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        if(mem[n])
            return mem[n];
        return mem[n] = climbStairs(n - 1, mem) + climbStairs(n - 2, mem); 
    }
    int climbStairs(int n) {
        vector<int> mem(n + 1, 0);
        return climbStairs(n, mem);
    }
};