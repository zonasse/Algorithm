class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() < 1) return {-1,-1};

        int first = getFirstPos(nums,target);
        int last = getLastPos(nums,target);
        return {first,last};
    }
    int getFirstPos(vector<int> &nums,int target){
        if(nums.empty()) return -1;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                if(mid == 0 || nums[mid] != nums[mid-1]){
                    return mid;
                }else{
                    right = mid-1;
                }
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return -1;
    }
    int getLastPos(vector<int> &nums,int target){
        if(nums.empty()) return -1;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                if(mid == nums.size()-1 || nums[mid] != nums[mid+1]){
                    return mid;
                }else{
                    left = mid+1;
                }
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return -1;
    }

};
