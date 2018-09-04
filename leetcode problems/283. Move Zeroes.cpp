class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() < 2) return;
        int left = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] != 0){
                nums[left++] = nums[i];
            }
        }
        while(left < nums.size()){
            nums[left++] = 0;
        }
    }
};
