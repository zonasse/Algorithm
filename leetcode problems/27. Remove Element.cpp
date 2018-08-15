class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int size = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == val) continue;
            nums[size++] = nums[i];
        }
        return size;
    }
};
