/*
 *  ≈–∂œ±‰Œª¥ 
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool judge_transfer_words(string s1,string s2){
        if(s1.empty() || s2.empty() || s1.size() != s2.size()){
            return false;
        }
        int _map[256] = {0};
        for(int i=0; i<s1.size(); ++i){
            _map[s1[i]]++;
        }
        for(int i=0; i<s2.size(); ++i){
            if(_map[s2[i]]-- == 0){
                return false;
            }
        }
        return true;

    }

};

int main(){
    string s1 = "aeddfc";
    string s2 = "dfceda";
    Solution s;
    printf("%d\n",s.judge_transfer_words(s1,s2));

    return 0;
}
