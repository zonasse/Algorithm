class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        int val = 9;
        int res = 10;
        for(int i=2; i<=n; ++i){
            val *= (9-i+2);
            res += val;
        }
        return res;
    }
};
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        int maxVal = pow(10,n);
        vector<bool> used(10,false);
        for(int i=1; i<=9; ++i){
            used[i] = true;
            res += search(i,maxVal,used);
            used[i] = false;
        }
        return res;
    }
    int search(int cur,int maxVal,vector<bool> used){
        int res = 0;
        if(cur < maxVal) res++;
        else return res;
        for(int i=0; i<=9; ++i){
            if(!used[i]){
                used[i] = true;
                res += search(cur*10+i,maxVal,used);
                used[i] = false;
            }
        }
        return res;
    }
};
