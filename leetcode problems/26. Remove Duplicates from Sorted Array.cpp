class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return size;
        for(vector<int> ::iterator it = nums.begin(); it != nums.end(); it++){
            while(*it == *(it+1) && it != nums.end()-1){
                nums.erase(it+1);
            }
        }
        return nums.size();
    }
};
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int size = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] == nums[i-1]) continue;
            nums[size++] = nums[i];
        }
        return size;
    }
};
