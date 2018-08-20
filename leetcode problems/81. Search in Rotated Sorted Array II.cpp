class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                while(left != mid && nums[left] == nums[mid]){
                    left++;
                }
                if(left == mid){
                    left = mid+1;
                    continue;
                }
            }
            if(nums[mid] != nums[left]){
                if(nums[mid] > nums[left]){
                    if(target >= nums[left] && target < nums[mid]){
                        right = mid-1;
                    }else{
                        left = mid+1;
                    }
                }else{
                    if(target <= nums[right] && target > nums[mid]){
                        left = mid+1;
                    }else{
                        right = mid-1;
                    }
                }
            }else{
                if(nums[mid] > nums[right]){
                    if(target >= nums[left] && target < nums[mid]){
                        right = mid-1;
                    }else{
                        left = mid+1;
                    }
                }else{
                    if(target > nums[mid] && target <= nums[right]){
                        left = mid+1;
                    }else{
                        right = mid-1;
                    }
                }
            }
        }
        return false;
    }
};
