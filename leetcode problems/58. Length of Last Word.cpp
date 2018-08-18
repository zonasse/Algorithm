class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = s.size()-1;
        int lastPre = last;
        while(last >= 0 && s[last] == ' '){
            last--;
            lastPre--;
        }
        if(last < 0) return 0;
        while(lastPre >= 0 && s[lastPre] != ' '){
            lastPre--;
        }
        return last - lastPre;

    }
};
