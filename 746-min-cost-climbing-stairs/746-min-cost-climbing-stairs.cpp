class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost, int indx, vector<int>& total_cost) {
        int totalLen = cost.size();
        if (totalLen - 2 <= indx) {
            return cost[indx];
        }

        if (total_cost[indx]) {
            return total_cost[indx];
        }

        return total_cost[indx] = min(minCostClimbingStairs (cost, indx + 2, total_cost), 
                                      minCostClimbingStairs (cost, indx + 1, total_cost)) + cost[indx];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> total_cost(cost.size() + 1);
        
        return min(minCostClimbingStairs (cost, 1, total_cost), minCostClimbingStairs (cost, 0, total_cost));        
    }
};