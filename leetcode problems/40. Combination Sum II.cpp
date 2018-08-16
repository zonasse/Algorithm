class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int> > ret;
        if(candidates.empty()) return {{}};
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        bool mark[candidates.size()];
        memset(mark,false,sizeof(mark));
        dfs(candidates,ret,temp,target,candidates.size()-1,mark);
        return vector<vector<int> >(ret.begin(),ret.end());
    }
    void dfs(vector<int>& candidates,set<vector<int> > &ret,vector<int> &temp,int target,int index,bool mark[]){
        if(target < 0) return;
        if(target == 0){
            ret.insert(temp);
            return;
        }
        if(index < 0) return;

        for(int i=0; i<=index; ++i){
            if(candidates[index-i] <= target && !mark[index-i]){
                temp.push_back(candidates[index-i]);
                mark[index-i] = true;
                dfs(candidates,ret,temp,target-candidates[index-i],index-i,mark);
                temp.pop_back();
                mark[index-i] = false;
            }

        }

    }
};
