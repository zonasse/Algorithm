class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> count(128,0);
        for(int i=0; i<s.size(); ++i){
            count[s[i]]++;
        }
        for(int i=0; i<s.size(); ++i){
            count[t[i]]--;
        }
        for(int i=0; i<128; ++i){
            if(count[i] != 0) return false;
        }
        return true;
    }
};
