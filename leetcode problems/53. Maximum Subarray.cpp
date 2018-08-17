class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int sum = 0;
        int maxSum = INT_MIN;
        for(int i=0; i<nums.size(); ++i){
            sum += nums[i];
            maxSum = max(maxSum,sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
};
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSub(nums,0,nums.size()-1);
    }
    int maxSub(vector<int> &nums,int left,int right){
        if(left >= right) return nums[left];
        int mid = left + (right-left) / 2;
        int leftMax = maxSub(nums,left,mid-1);
        int rightMax = maxSub(nums,mid+1,right);
        int midMax = nums[mid];
        int t = midMax;
        for(int i=mid-1; i>=left; --i){
            t += nums[i];
            midMax = max(midMax,t);
        }
        t = midMax;
        for(int i=mid+1; i<=right; ++i){
            t += nums[i];
            midMax = max(midMax,t);
        }
        return max(midMax,max(leftMax,rightMax));
    }
};
