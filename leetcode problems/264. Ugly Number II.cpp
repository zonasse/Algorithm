class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 7) return n;
        vector<int> res(n);
        res[0] = 1;
        int n2 = 0;
        int n3 = 0;
        int n5 = 0;
        for(int i=1; i<n; ++i){
            res[i] = min(res[n2] * 2,min(res[n3] * 3,res[n5] * 5));
            if(res[i] == res[n2] * 2) n2++;
            if(res[i] == res[n3] * 3) n3++;
            if(res[i] == res[n5] * 5) n5++;
        }
        return res[n-1];
    }
};
