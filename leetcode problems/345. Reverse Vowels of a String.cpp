class Solution {
public:
    string reverseVowels(string s) {
        if(s.size() < 2) return s;
        vector<char> temp = {'a','e','i','o','u','A','E','I','O','U'};
        set<char> char_set(temp.begin(),temp.end());
        int left = 0;
        int right = s.size()-1;
        string res = s;
        while(left < right){
            if(char_set.count(res[left]) && char_set.count(res[right])){
                swap(res[left++],res[right--]);
            }else if(char_set.count(res[left])){
                right--;
            }else{
                left++;
            }
        }
        return res;
    }
};
