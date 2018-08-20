class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) return res;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        dfs(nums,0,temp,res);
        return res;
    }
    void dfs(vector<int> &nums,int cur,vector<int> &temp,vector<vector<int> > &res){
        res.push_back(temp);
        for(int i=cur; i<nums.size(); ++i){
            temp.push_back(nums[i]);
            dfs(nums,i+1,temp,res);
            temp.pop_back();
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
    }
};
