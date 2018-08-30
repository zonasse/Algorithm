class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1) return nums.empty() ? 0:nums[0];
        return max(subRob(nums,0,nums.size()-2),subRob(nums,1,nums.size()-1));
    }
    int subRob(vector<int> &nums,int left,int right){
        if(left == right) return nums[left];
        vector<int> dp(right-left+1);
        dp[0] = nums[left];
        dp[1] = max(nums[left+1],dp[0]);
        for(int i=2; i<=right-left; ++i){
            dp[i] = max(dp[i-2]+nums[left+i],dp[i-1]);
        }
        return dp[right-left];
    }
};
