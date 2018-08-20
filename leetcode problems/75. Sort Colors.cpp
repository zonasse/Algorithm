class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;
        quickSort(nums,0,nums.size()-1);

    }
    void quickSort(vector<int> &nums,int left,int right){
        if(left >= right) return;
        int lt = left;
        int i = left+1;
        int gt = right;
        int pivot = nums[left];
        while(i <= gt){
            if(nums[i] > pivot){
                swap(nums[i],nums[gt--]);
            }else if(nums[i] < pivot){
                swap(nums[i++],nums[lt++]);
            }else{
                i++;
            }
        }
        quickSort(nums,left,lt-1);
        quickSort(nums,gt+1,right);
    }
};
