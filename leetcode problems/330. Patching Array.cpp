class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;
        int res = 0;
        int i = 0;
        while(miss <= n){
            if(i < nums.size() && nums[i] <= miss){
                miss += nums[i++];
            }else{
                miss += miss;
                res++;
            }
        }
        return res;
    }
};
