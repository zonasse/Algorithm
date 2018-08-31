class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < 2 || k < 0) return false;
        unordered_map<int,int> M;
        for(int i=0; i<nums.size(); ++i){
            if(M.find(nums[i]) == M.end()){
                M[nums[i]] = i;
            }else{
                int index = M[nums[i]];
                if(abs(i-index) <= k){
                    return true;
                }else{
                    M[nums[i]] = i;
                }
            }
        }
        return false;
    }
};
