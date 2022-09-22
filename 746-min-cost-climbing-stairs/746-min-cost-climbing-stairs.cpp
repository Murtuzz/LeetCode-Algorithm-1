class Solution {
    public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size() - 1;
        
        for (int i = len - 2; i >= 0; i--) {
            cost[i] += min(cost[i + 1], cost[i + 2]); 
        }

        return min (cost[0], cost[1]);
    }
};