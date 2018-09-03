// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(n) == false) return -1;
        int left = 1;
        int right = n;
        int res = n;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(isBadVersion(mid)){
                res = mid;
                right = mid-1;
            }else{
                left = mid + 1;
            }
        }
        return res;
    }
};
