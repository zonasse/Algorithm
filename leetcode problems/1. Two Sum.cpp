/*
 *  思路：利用无序哈希表存储值到索引的映射
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        if(nums.empty()){
            return ret;
        }
        unordered_map<int,int> M;
        for(int i=0; i<nums.size(); ++i){
            M[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); ++i){
            int other = target - nums[i];
            if(M.count(other) && M[other] != i){
                ret.push_back(i);
                ret.push_back(M[other]);
                break;
            }
        }
        return ret;
    }
};
