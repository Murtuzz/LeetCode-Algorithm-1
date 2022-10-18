class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        int i = 0, j = 0;
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>>ans;
        vector<int> set(2);
        while(i < n && j < m) {
            int first_low = firstList[i][0];
            int first_high = firstList[i][1];
            int second_low = secondList[j][0];
            int second_high = secondList[j][1];
            int low = max(first_low,second_low);
            int high = min(first_high,second_high);

            if(low <= high) {
                set[0] = low;
                set[1] = high;
                ans.push_back(set);
            }
            
            if(first_high < second_high) i++;
            else j++;
        }
        return ans;
    }
};