class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> ret;
        for(int i=0; i<numbers.size(); ++i){
            ret.push_back(to_string(numbers[i]));
        }
        sort(ret.begin(),ret.end(),cmp);
        string ans = "";
        for(int i=0; i<ret.size(); ++i){
            ans = ans + ret[i];
        }
        return ans;
    }
    static bool cmp(const string s1,const string s2){
        return s1+s2 < s2+s1;
    }
};
