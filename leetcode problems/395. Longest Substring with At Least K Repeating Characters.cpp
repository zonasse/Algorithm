//O(n^3)暴力解法，超时
class Solution1 {
public:
    int longestSubstring(string s, int k) {
        if(k <= 0 || s.size() == 0) return 0;
        int res = 0;
        for(int i=0; i<s.size(); ++i){
            for(int j=i; j<s.size(); ++j){
                res = max(res,check(s,i,j,k));
            }
        }
        return res;
    }
    int check(string s,int left, int right,int k){
        map<char,int> m;
        for(int i=left; i<=right; ++i){
            m[s[i]]++;
        }
        map<char,int> ::iterator it;
        for(it = m.begin(); it != m.end(); ++it){
            if(it->second < k){
                return 0;
            }
        }
        return right-left+1;
    }
};
//AC
class Solution2 {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int maxIdx = 0;
        int res = 0;
        int mark[128] = {0};
        bool flag = true;
        for(char c : s) mark[c]++;
        for(int i=0; i<n; ++i){
            if(mark[s[i]] < k){
                res = max(res,longestSubstring(s.substr(maxIdx,i-maxIdx),k));
                flag = false;
                maxIdx = i+1;
            }
        }
        return flag == true ? n : max(res,longestSubstring(s.substr(maxIdx,n-maxIdx),k));
    }
};