class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long ,int> M;
        int j=0;
        for(int i=0; i<nums.size(); ++i){
            if(i-j > k) M.erase(nums[j++]);
            auto a = M.lower_bound((long long)nums[i] - t);
            if(a != M.end() && abs(nums[i]-a->first) <= t) return true;
            M[nums[i]] = i;
        }
        return false;
    }
};
