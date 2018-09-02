class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() < 2) return {};
        vector<int> res(nums.size());
        res[0] = nums[0];
        for(int i=1; i<nums.size(); ++i){
            res[i] = res[i-1]*nums[i];
        }
        int temp = 1;
        for(int i=nums.size()-1; i>0; --i){
            res[i] = res[i-1]*temp;
            temp*=nums[i];
        }
        res[0] = temp;
        return res;
    }
};
