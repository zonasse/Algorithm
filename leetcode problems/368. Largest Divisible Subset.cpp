class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),0);
        vector<int> parent(nums.size(),0);
        vector<int> res;
        int maxLen = 0,startIndex = 0;
        for(int i=nums.size()-1; i>=0; --i){
            for(int j=i; j<nums.size(); ++j){
                if(dp[i] < dp[j] + 1 && nums[j] % nums[i] == 0){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if(dp[i] > maxLen){
                        maxLen = dp[i];
                        startIndex = i;
                    }
                }
            }
        }
        for(int i=0; i<maxLen; ++i){
            res.push_back(nums[startIndex]);
            startIndex = parent[startIndex];
        }
        return res;
    }
};
