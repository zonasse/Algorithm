class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(s.empty() || words.empty()) return ret;
        int sLen = s.size();
        int wLen = words.size();
        int perLen = words[0].size();
        if(perLen * wLen > sLen) return ret;
        unordered_map<string,int> M;
        unordered_map<string,int> temp;
        for(int i=0; i<wLen; ++i){
            M[words[i]]++;
        }
        for(int i=0; i+wLen*perLen-1 < sLen; ++i){
            int j=i;
            temp.clear();
            while(j <= i+wLen*perLen-1){
                string sub = s.substr(j,perLen);
                temp[sub]++;
                if(M[sub] < temp[sub]){
                    break;
                }else{
                    j+=perLen;
                }
                if(j > i+wLen*perLen-1){
                    ret.push_back(i);
                }
            }

        }
        return ret;
    }
};
