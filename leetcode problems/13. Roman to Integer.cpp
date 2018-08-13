class Solution {
public:
    int romanToInt(string s) {
        map<char,int> M = {{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
        int ret = 0;
        for(int i=0; i<s.size(); ++i){
            if(i == s.size()-1 || M[s[i]] >= M[s[i+1]]){
                ret += M[s[i]];
            }else{
                ret -= M[s[i]];
            }
        }
        return ret;
    }
};
