#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string reverse_string(string s){
        string res = s;
        reverse(res.begin(),res.end());
        res.append(" ");
        int start = 0;
        int end = 0;
        while(end < res.size()){
            if(res[end] == ' '){
                _reverse(res,start,end-1);
                start = end+1;
                end = start;
                continue;
            }
            end++;
        }
        res.erase(res.size()-1);
        return res;
    }
    void _reverse(string &s,int start,int end){
        if(start == end) return;
        while(start <= end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};
int main(){
    string s = "abc de f";
    //string s = "abc";
    //string s = "a b";


    Solution handle;
    printf("%s\n",(handle.reverse_string(s)).c_str());
    return 0;
}
