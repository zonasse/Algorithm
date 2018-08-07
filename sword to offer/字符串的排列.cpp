class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ret;
        if(str.empty()){
            return ret;
        }
        find(str,0,ret);
        sort(ret.begin(),ret.end());
        return ret;
    }
    void find(string s,int cur,vector<string> &ret){
        if(cur == s.size()){
            ret.push_back(s);
        }else{
            for(int i=cur; i<s.size(); ++i){
                if(i != cur && s[i] == s[cur]) continue;
                swap(s[cur],s[i]);
                find(s,cur+1,ret);
                swap(s[cur],s[i]);
            }
        }
    }
    void swap(char &a,char &b){
        char temp = a;
        a = b;
        b = temp;
    }
};
