class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int dup = 1;
        int size = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] == nums[i-1]){
                dup++;
                if(dup < 3){
                    nums[size++] = nums[i];
                }else{
                    dup--;
                }
            }else{
                dup = 1;
                nums[size++] = nums[i];
            }
        }
        return size;
    }
};
