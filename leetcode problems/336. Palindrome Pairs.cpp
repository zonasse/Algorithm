class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > res;
        unordered_map<string,int> M;
        set<int> len_set;
        for(int i=0; i<words.size(); ++i){
            M[words[i]] = i;
            len_set.insert(words[i].size());
        }
        for(int i=0; i<words.size(); ++i){
            string cur = words[i];
            int len = cur.size();
            reverse(cur.begin(),cur.end());
            if(M.count(cur) && M[cur] != i){
                res.push_back({i,M[cur]});
            }
            for(auto it = len_set.begin(); it != len_set.find(len); ++it){
                int d = *it;
                if(judge(cur,0,len-d-1) && M.count(cur.substr(len-d))){
                    res.push_back({i,M[cur.substr(len-d)]});
                }
                if(judge(cur,d,len-1) && M.count(cur.substr(0,d))){
                    res.push_back({M[cur.substr(0,d)],i});
                }
            }
        }
        return res;
    }
    bool judge(string s,int left,int right){
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
};
/*
 * ³¬Ê±
 */
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > res;
        for(int i=0; i<words.size() ;++i){
            for(int j=0; j<i; ++j){
                if(judge(words[i] + words[j])){
                    res.push_back({i,j});
                }
                if(judge(words[j] + words[i])){
                    res.push_back({j,i});
                }
            }
        }
        return res;
    }
    bool judge(string s){
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }
};
