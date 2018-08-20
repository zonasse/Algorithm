class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        dfs(nums,0,temp,res);
        return res;
    }
    void dfs(vector<int>& nums,int cur,vector<int> &temp,vector<vector<int> > &res){
        res.push_back(temp);
        for(int i=cur; i<nums.size(); ++i){
            temp.push_back(nums[i]);
            dfs(nums,i+1,temp,res);
            temp.pop_back();
        }
    }
};
