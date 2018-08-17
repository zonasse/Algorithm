class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> temp;
        bool mark[nums.size()];
        memset(mark,false,sizeof(mark));
        dfs(nums,ret,temp,mark);
        return ret;
    }
    void dfs(vector<int> &nums,vector<vector<int> > &ret,vector<int> &temp,bool mark[]){
        if(temp.size() == nums.size()){
            ret.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); ++i){
            if(mark[i] == false){
                mark[i] = true;
                temp.push_back(nums[i]);
                dfs(nums,ret,temp,mark);
                temp.pop_back();
                mark[i] = false;
            }
        }
    }
};
