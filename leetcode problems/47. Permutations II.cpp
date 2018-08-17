class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ret;
        sort(nums.begin(),nums.end());
        dfs(nums,ret,0);
        return ret;
    }
    void dfs(vector<int> &nums,vector<vector<int> > &ret,int index){
        if(index == nums.size()-1){
            ret.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); ++i){
            if(i != index && nums[i] == nums[index]){
                continue;
            }
            swap(nums[i],nums[index]);
            dfs(nums,ret,index+1);
        }
    }
};
