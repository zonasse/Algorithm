class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        int n = nums.size();
        if(n < 4){
            return ret;
        }
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-3; ++i){
            if(i>0 && nums[i] == nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if(nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;
            for(int j=i+1; j<n-2; ++j){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                if(nums[i]+nums[j]+nums[n-1]+nums[n-2] < target) continue;
                int left = j+1;
                int right = n-1;
                while(left < right){
                    int cur = nums[i]+nums[j]+nums[left]+nums[right];
                    if(cur > target){
                        right--;
                    }else if(cur < target){
                        left++;
                    }else{
                        vector<int> temp = {nums[i],nums[j],nums[left],nums[right]};
                        ret.push_back(temp);
                        do{
                            left++;
                        }while(left < right && nums[left] == nums[left-1]);
                        do{
                            right--;
                        }while(left < right && nums[right] == nums[right+1]);
                    }
                }
            }
        }
        return ret;
    }
};