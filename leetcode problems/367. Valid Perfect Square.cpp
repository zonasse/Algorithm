class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0;
        long right = num;
        while(left <= right){
            long mid = left + (right-left)/2;
            long cur = mid*mid;
            if(cur == num){
                return true;
            }else if(cur > num){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return false;
    }
};
