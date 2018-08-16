class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                if(mid == 0 || nums[mid-1] < target) return mid;
                right = mid-1;
            }else{
                if(mid == nums.size()-1 || nums[mid+1] > target) return mid+1;
                left = mid+1;
            }
        }
        return 0;
    }
};
