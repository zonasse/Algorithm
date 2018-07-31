#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*
     * 方法1
     */
    int kmp(string ms,string ss){
        if(ms.size() < 1 || ss.size() > ms.size()){
            return -1;
        }
        vector<int> next = get_next_array(ss);
        int s1 = 0;
        int s2 = 0;
        while(s1 < ms.size() && s2 < ss.size()){
            if(ms[s1] == ss[s2]){
                s1++;
                s2++;
            }else{
                if(next[s2] == -1){
                    s1++;
                }else{
                    s2 = next[s2];
                }
            }
        }
        return s2 == ss.size()? (s1-s2):-1;
    }
    vector<int> get_next_array(string ss){

        vector<int> next(ss.size(),0);
        next[0] = -1;
        next[1] = 0;
        int pos = 2;
        int cn = 0;
        while(pos < ss.size()){
            if(ss[pos-1] == ss[cn]){
                cn++;
                ss[pos] = cn;
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
    /* 方法2
    int kmp(string ms, string ss){
        if( ss.size() < 1 || ms.size() < ss.size()){
            return -1;
        }
        vector<int> nextArr = get_next_array(ss);
        int i,k;
        for(i=0,k=0; i<ms.size(); ++i){
            while(k > 0 && ms[i] != ss[k]){
                k = nextArr[k-1];
            }
            if(ms[i] == ss[k]){
                k++;
            }
            if(k == ss.size()){
                printf("i = %d\n",i);
                printf("k = %d\n",k);
                return i-k+1;
            }
        }
        return -1;
    }
    vector<int> get_next_array(string ss){
        vector<int> next(ss.size(),0);
        int i,k;
        for(i=1,k=0; i<ss.size(); ++i){
            while(k > 0 && ss[i] != ss[k]){
                k = next[k-1];
            }
            if(ss[i] == ss[k]){
                k++;
            }
            next[i] = k;
        }
        return next;
    }*/


};

int main(){
    string ms = "abcabcababaccc";
    string ss = "ababa";
    //string ms = "deabcabdabc";
    //string ss = "abcabd";
    Solution s;
    printf("%d\n",s.kmp(ms,ss));
    return 0;
}
