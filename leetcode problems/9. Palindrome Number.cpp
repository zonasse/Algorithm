class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        if(x < 10){
            return true;
        }
        if(x == reverseInt(x)){
            return true;
        }
        return false;
    }
    int reverseInt(int x){
        int res = 0;
        while(x){
            res = res*10+x%10;
            x/=10;
        }
        return res;
    }
};
