class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return;
        int pos = size-1;
        while(pos > 0 && nums[pos] <= nums[pos-1]){
            --pos;
        }
        if(pos == 0){
            reverse(nums.begin(),nums.end());
            return;
        }
        if(pos == size-1){
            swap(nums[pos],nums[pos-1]);
            return;
        }
        int begin = size-1;
        while(begin > pos && nums[begin] <= nums[pos-1]){
            --begin;
        }
        swap(nums[pos-1],nums[begin]);
        sort(nums.begin()+pos,nums.end());

    }
};
