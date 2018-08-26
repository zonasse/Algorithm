class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0, n = ratings.size();
        vector<int> candys(n,1);
        for(int i=0; i<n-1; ++i){
            if(ratings[i+1] > ratings[i]) candys[i+1] = candys[i] + 1;
        }
        for(int i=n-1; i > 0; --i){
            if(ratings[i-1] > ratings[i]) candys[i-1] = max(candys[i-1],candys[i] + 1);
        }
        for(int candy : candys) res += candy;
        return res;
    }
};
