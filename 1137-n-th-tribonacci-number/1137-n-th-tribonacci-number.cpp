class Solution {
public:
    int tribonacci(int n, vector<int> &mem) {
        if (n == 0) {
            return 0;
        } else if (n <= 2) {
            return 1;
        } else if (mem[n]) {
            return mem[n];
        }
        return mem[n] = tribonacci(n - 1, mem) + tribonacci(n - 2, mem) + tribonacci(n - 3, mem);
    }
    int tribonacci(int n) {
        vector<int> mem(n + 1, 0);
        return tribonacci(n, mem);
    }
};