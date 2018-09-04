class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string,char> M;
        str += ' ';
        vector<bool> mark(256,false);
        string word = "";
        int pos = 0;
        for(int i=0; i<str.size(); ++i){
            if(str[i] != ' '){
                word += str[i];
            }else{
                if(pos >= pattern.size()) return false;
                if(M.find(word) == M.end()){
                    if(mark[pattern[pos]] == true){
                        return false;
                    }
                    M[word] = pattern[pos];
                    mark[pattern[pos]] = true;
                }else{
                    if(M[word] != pattern[pos]) return false;
                }
                word = "";
                pos++;
            }
        }
        if(pos != pattern.size()) return false;
        return true;
    }
};
