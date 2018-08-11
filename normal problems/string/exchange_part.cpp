/*
 *  ·´×ªµ¥´Ê
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void exchange_part(string &s,int i){
        _reverse(s,0,i);
        _reverse(s,i+1,s.size()-1);
        reverse(s.begin(),s.end());

    }
private:
    void _reverse(string &s,int start,int end){
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
    string s = "ABCDE";
    Solution handle;
    handle.exchange_part(s,2);
    printf("%s\n",s.c_str());
    return 0;
}
