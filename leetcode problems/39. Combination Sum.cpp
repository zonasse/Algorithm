class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ret;
        if(candidates.empty()) return ret;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        dfs(candidates,ret,target,temp,candidates.size()-1);
        return ret;
    }
    void dfs(vector<int>& candidates,vector<vector<int> > &ret,int target,vector<int> &temp,int index){
        if(target < 0) return;
        if(target == 0){
            ret.push_back(temp);
            return;
        }
        if(index < 0) return;
        for(int i=0; i<=index; ++i){
            if(candidates[index-i] <= target){
                temp.push_back(candidates[index-i]);
                dfs(candidates,ret,target-candidates[index-i],temp,index-i);
                temp.pop_back();
            }
        }

    }
};
