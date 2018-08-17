class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty()) return 0;
        int jump = 0;
        int next = 0;
        int cur = 0;
        for(int i=0; i<nums.size(); ++i){
            if(cur < i){
                jump++;
                cur = next;
            }
            next = max(next,i+nums[i]);
        }
        return jump;
    }
};
