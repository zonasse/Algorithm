class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size() < 3) return ret;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-2; ++i){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            int target = 0-nums[i];
            while(left < right){
                if(nums[left] + nums[right] == target){
                    ret.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }else if(nums[left] + nums[right] > target){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return ret;
    }
};