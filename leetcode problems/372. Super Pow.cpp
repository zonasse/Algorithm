class Solution {
public:
    int superPow(int a, vector<int>& b) {

        long long res = 1;
        for(int i=0; i<b.size(); ++i){
            res = solve(res,10) * solve(a,b[i]) % 1337;
        }
        return res;
    }
    int solve(int a,int b){
        if(!b) return 1;
        if(b == 1) return a%1337;
        return solve(a,b/2) * solve(a,b-b/2) % 1337;
    }
};
