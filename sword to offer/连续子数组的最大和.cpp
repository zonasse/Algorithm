class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() <= 0){
            return 0;
        }
        vector<int> dp(array.size()+1);
        dp[0] = array[0];
        for(int i=1; i<array.size(); ++i){
            if(dp[i-1] <= 0){
                dp[i] = array[i];
            }else{
                dp[i] = dp[i-1] + array[i];
            }
        }
        int ret = dp[0];
        for(int i=1; i<array.size(); ++i){
            ret = max(dp[i],ret);
        }
        return ret;
    }
};
