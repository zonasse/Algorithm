class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(),0);
        int ans = 0;
        for(int i=0; i<nums.size(); ++i){
            dp[i] = 1;
            for(int j=0; j<i; ++j){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(),0);
        vector<int> ends(nums.size(),0);

        dp[0] = 1;
        ends[0] = nums[0];
        int left = 0;
        int right = 0;
        int availableArea = 0;

        int ans = 1;

        for(int i=1; i<nums.size(); ++i){
            left = 0;
            right = availableArea;
            while(left <= right){
                int mid = left + (right-left)/2;
                if(nums[i] > ends[mid]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
            availableArea = max(left,availableArea);
            ends[left] = nums[i];
            dp[i] = left + 1;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
