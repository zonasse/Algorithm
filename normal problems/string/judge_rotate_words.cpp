#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool judge_rotate_words(string s1,string s2){
        if(s1.empty() || s2.empty() || s1.size() != s2.size()){
            return false;
        }
        s1 += s1;
        //用kmp判断s2是否能在s1中完成匹配
        return can_kmp(s1,s2);

    }
    bool can_kmp(string ms, string ss){
        if(ms.empty() || ss.empty() || ms.size() < ss.size()){
            return false;
        }
        vector<int> next = get_next_array(ss);
        int s1 = 0;
        int s2 = 0;
        while(s1 < ms.size() && s2 < ss.size()){
            if(ms[s1] == ss[s2]){
                s1++;
                s2++;
            }else{
                if(next[s2] > 0){
                    s2 = next[s2];
                }else{
                    s1++;
                }
            }
        }
        return s2 == ss.size();
    }
    vector<int> get_next_array(string ss){
        if(ss.size() < 2){
            return {};
        }
        vector<int> next(ss.size(),0);
        next[0] = -1;
        next[1] = 0;
        int pos = 2;
        int cn = 0;
        while(pos <= ss.size()){
            if(ss[pos-1] == ss[cn]){
                cn++;
                next[pos] = cn;
                pos++;
            }else{
                if(cn > 0){
                    cn = next[cn];
                }else{
                    next[pos] = 0;
                    pos++;
                }
            }
        }
        return next;
    }


};

int main(){
    string s1 = "abcdef";
    string s2 = "cdefab";
    Solution s;
    printf("%d\n",s.judge_rotate_words(s1,s2));

    return 0;
}
