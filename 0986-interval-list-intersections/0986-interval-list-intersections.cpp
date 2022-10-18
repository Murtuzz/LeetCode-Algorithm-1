class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        int i = 0, j = 0;
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>>ans;
        vector<int> set(2);
        
        while(i < n && j < m) {
            int low = max(firstList[i][0], secondList[j][0]);
            int high = min(firstList[i][1], secondList[j][1]);

            if(low <= high) {
                set[0] = low;
                set[1] = high;
                ans.push_back(set);
            }
            
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return ans;
    }
};