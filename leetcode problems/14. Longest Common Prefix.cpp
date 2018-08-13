class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int minLen = INT_MAX;
        for(int i=0; i<strs.size(); ++i){
            if(strs[i].size() < minLen){
                minLen = strs[i].size();
            }
        }
        for(int i=0; i<minLen; ++i){
            for(int j=0; j<strs.size()-1; ++j){
                if(strs[j][i] != strs[j+1][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0].substr(0,minLen);
    }
};
