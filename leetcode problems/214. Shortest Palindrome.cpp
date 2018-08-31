class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        string pattern = s+"#"+r;
        vector<int> next = getNextArray(pattern);
        return r.substr(0,s.size()-next.back())+s;
    }
    /*
     * 此处next数组多求最后一位
     */
    vector<int> getNextArray(string s){
        if(s.size() == 1) return {-1};
        vector<int> next(s.size()+1);
        next[0] = -1;
        next[1] = 0;
        int pos = 2;
        int cn = 0;
        while(pos < s.size()+1){
            if(s[pos-1] == s[cn]){
                next[pos++] = ++cn;
            }else if(cn > 0){
                cn = next[cn];
            }else{
                next[pos++] = 0;
            }
        }
        return next;
    }
};
