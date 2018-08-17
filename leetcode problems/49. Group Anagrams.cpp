class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ret;
        unordered_map<string,vector<string> > M;
        for(int i=0; i<strs.size(); ++i){
            string str = strs[i];
            string ss = str;
            sort(ss.begin(),ss.end());
            M[ss].push_back(str);
        }
        for(unordered_map<string,vector<string> > ::iterator it = M.begin(); it != M.end(); ++it){
            ret.push_back(it->second);
        }
        return ret;
    }
};
