/*
 *  最长不重复子串
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //1.方法一，暴力
    int longest_unique_substring1(string str){
        int ans = 0;
        for(int i=0; i<str.size(); ++i){
            for(int j=i+1; j<=str.size(); ++j){
                if(_unique(str,i,j)){
                    ans = max(ans,j-i);
                }
            }
        }
        return ans;

    }
    bool _unique(string str,int start,int end){
        set<char> char_set;
        for(int i=start; i<end; ++i){
            if(char_set.find(str[i]) == char_set.end()){
                char_set.insert(str[i]);
            }else{
                return false;
            }
        }
        return true;
    }
    //2.方法二，滑动窗口
    int longest_unique_substring2(string str){
        int i=0,j=0;
        int ans = 0;
        set<char> char_set;
        while(i < str.size() && j < str.size()){
            if(char_set.find(str[j]) == char_set.end()){
                char_set.insert(str[j]);
                ans = max(ans,j-i+1);
                j++;
            }else{
                char_set.erase(str[i]);
                i++;
            }
        }
        return ans;
    }
    //3.方法3
    int longest_unique_substring3(string str) {
        int hash[256] = {-1};
        int prev = 0,max_len = 0;
        for(int i=0; i<str.size(); ++i){
            if(hash[str[i]] != -1){
                if(hash[str[i]] >= prev){
                    prev = hash[str[i]]+1;
                }
                hash[str[i]] = i;
            }else{
                hash[str[i]] = i;
            }
            max_len = max(max_len,i-prev+1);
        }
        return max_len;
    }

};

int main(){
    string str = "abcabcbb";
    //string str = "bbbbb";
    //string str = "pwwkew";

    Solution s;
    int ans = s.longest_unique_substring3(str);
    printf("%d\n",ans);

    return 0;
}
