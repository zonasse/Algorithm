class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m < n) return "";
        int map[256];
        memset(map,0,sizeof(map));
        for(int i=0; i<n; ++i){
            map[t[i]]++;
        }
        int resultLeft = 0;
        int match = n;
        int left = 0;
        int right = 0;
        int minLen = INT_MAX;
        while(right < m){
            map[s[right]]--;
            if(map[s[right]] >= 0){
                match--;
            }
            if(match == 0){
                while(map[s[left]] < 0){
                    map[s[left++]]++;
                }
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    resultLeft = left;
                }
                match++;
                map[s[left++]]++;
            }
            right++;
        }
        return minLen == INT_MAX ? "":s.substr(resultLeft,minLen);
    }
};
