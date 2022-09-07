class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
     
        vector<int> rslt(2,0);
        int low = 0, high = numbers.size()-1;
        
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                rslt[0] = ++low;
                rslt[1] = ++high;
                break;
            } else if (sum > target) {
                high--;
            } else {
                low++;
            }
        }
        return rslt;
    }
};