// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersionIndex(long low, long high) {
        long mid = (low + high) / 2;
        if (isBadVersion(mid) && !isBadVersion(mid-1)) {
            return mid;
        } else if (isBadVersion(mid)) {
            return firstBadVersionIndex(low, (mid - 1));
        } else {
            return firstBadVersionIndex((mid + 1), high);
        }
    }
    int firstBadVersion(int n) {
        if(isBadVersion(1)){
            return 1;   
        }
        return firstBadVersionIndex(2, n);
    }
};