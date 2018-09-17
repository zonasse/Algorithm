class Solution1 {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);
        for(int i=0; i<num; ++i){
            if(i % 2 == 0){
                dp[i+1] = dp[i] + 1;
            }else{
                dp[i+1] = dp[i/2 + 1];
            }
        }
        return dp;
    }
};
class Solution2 {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0; i<=num; ++i){
            int sum = 0;
            int temp = i;
            while(temp){
                sum++;
                temp = (temp-1)&temp;
            }
            res.push_back(sum);
        }
        return res;
    }
};
