class Solution {
public:
    int strStr(string s, string p) {
        if(p.empty()) return 0;
        if(s.size() < p.size()) return -1;
        vector<int> next = getNextArray(p);
        int si = 0;
        int pi = 0;
        while(si < s.size() && p < p.size()){
            if(s[si] == p[pi]){
                si++;
                pi++;
            }else if(next[pi] == -1){
                si++;
            }else{
                pi = next[pi];
            }
        }
        return pi == p.size() ? si-pi : -1;

    }
    vector<int> getNextArray(string p){
        if(p.size() == 1) return {-1};
        vector<int> next(p.size());
        next[0] = -1;
        next[1] = 0;
        int pi = 2;
        int cn = 0;
        while(pi < p.size()){
            if(p[pi-1] == pi[cn]){
                next[pi++] = ++cn;
            }else if(cn > 0){
                cn = next[cn];
            }else{
                next[pi++] = 0;
            }
        }
        return next;
    }
};
