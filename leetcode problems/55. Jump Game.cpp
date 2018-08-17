class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        for(int i=0; i<nums.size(); ++i){
            if(i > maxIdx || maxIdx >= nums.size()-1) break;
            maxIdx = max(maxIdx,i+nums[i]);
        }
        return maxIdx >= nums.size()-1;
    }
};
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); ++i){
            dp[i] = max(dp[i-1]-1,nums[i-1]-1);
            if(dp[i] < 0) return false;
        }
        return dp[dp.size()-1] >= 0;
    }
};
