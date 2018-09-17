class Solution {
public:
    string reverseString(string s) {
        string res = s;
        int left = 0;
        int right = res.size() - 1;
        while(left < right){
            swap(res[left++],res[right--]);
        }
        return res;
    }
};
