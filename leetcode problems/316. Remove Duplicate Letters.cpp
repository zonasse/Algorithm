class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[256] = {0},visited[256] = {0};
        for(char ch : s) m[ch]++;
        string res = "0";
        for(char ch : s){
            m[ch]--;
            if(visited[ch]) continue;
            while(ch < res.back() && m[res.back()]){
                visited[res.back()] = 0;
                res.pop_back();
            }
            res.push_back(ch);
            visited[ch] = 1;
        }
        return res.substr(1);
    }
};
