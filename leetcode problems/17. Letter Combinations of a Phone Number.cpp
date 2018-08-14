vector<string> numbers = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty()) return ret;

        string cur = "";
        dfs(digits,0,ret,cur);
        return ret;
    }
    void dfs(string &digits,int index,vector<string> &ret,string &cur){
        if(index == digits.size()){
            ret.push_back(cur);
            return;
        }
        string stringToNumber = numbers[digits[index]-'2'];
        for(int i=0; i<stringToNumber.size(); ++i){
            cur += stringToNumber[i];
            dfs(digits,index+1,ret,cur);
            cur.pop_back();
        }
    }
};