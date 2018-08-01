#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string min_combine_string(vector<string> strs){
        string res = "";
        sort(strs.begin(),strs.end(),compare);
        for(int i=0; i<strs.size(); ++i){
            res += strs[i];
        }
        return res;

    }
    static bool compare(const string &s1,const string &s2){
        return s1+s2<s2+s1;
    }

};

int main(){
    vector<string> strs;
    strs.push_back("abe");
    strs.push_back("ika");
    strs.push_back("vdc");
    Solution s;
    string res = s.min_combine_string(strs);
    printf("%s\n",res.c_str());
    return 0;
}
