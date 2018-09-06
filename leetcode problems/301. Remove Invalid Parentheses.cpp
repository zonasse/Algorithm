class Solution1 {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited;
        queue<string> Q;
        bool found = false;
        visited.insert(s);
        Q.push(s);
        while(Q.empty() == false){
            string temp = Q.front();
            Q.pop();
            if(isvalid(temp)){
                res.push_back(temp);
                found = true;
            }
            if(found) continue;
            for(int i=0; i<temp.size(); ++i){
                if(temp[i] != '(' && temp[i] != ')') continue;
                string str = temp.substr(0,i) + temp.substr(i+1);
                if(!visited.count(str)){
                    Q.push(str);
                    visited.insert(str);
                }
            }
        }
        return res;
    }
    bool isvalid(string temp){
        int cnt = 0;
        for(int i=0; i<temp.size(); ++i){
            if(temp[i] == '('){
                ++cnt;
            }else if(temp[i] == ')' && --cnt < 0) return false;
        }
        return cnt == 0 ;
    }
};
class Solution2 {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int cnt1 = 0,cnt2 = 0;
        for(char c : s){
            cnt1 += (c == '(');
            if(cnt1 == 0) cnt2 += (c == ')');
            else cnt1 -= (c == ')');
        }
        dfs(s,0,cnt1,cnt2,res);
        return res;
    }
    void dfs(string s,int cur,int cnt1,int cnt2,vector<string> &res){
        if(cnt1 == 0 && cnt2 == 0){
            if(isvalid(s)){
                res.push_back(s);
            }
            return;
        }
        for(int i=cur; i<s.size(); ++i){
            if(i != cur && s[i] == s[i-1]) continue;
            if(cnt1 > 0 && s[i] == '('){
                dfs(s.substr(0,i)+s.substr(i+1),i,cnt1-1,cnt2,res);
            }
            if(cnt2 > 0 && s[i] == ')'){
                dfs(s.substr(0,i)+s.substr(i+1),i,cnt1,cnt2-1,res);
            }
        }
    }
    bool isvalid(string s){
        int cnt = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '(') cnt++;
            else if(s[i] == ')' && --cnt < 0) return false;
        }
        return cnt == 0;
    }
};
