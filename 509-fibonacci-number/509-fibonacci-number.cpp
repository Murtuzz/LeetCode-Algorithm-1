class Solution {
public:    
    int fib(int n, vector<int> &mem) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (mem[n]) {
            return mem[n];
        }
        return mem[n] = fib (n - 1, mem) + fib (n - 2, mem);
    }
    
    int fib(int n) {
        vector<int>mem(n+1);
        return fib(n, mem);
    }
    
};