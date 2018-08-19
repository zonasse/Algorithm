class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int aIndex = a.size()-1;
        int bIndex = b.size()-1;
        int carry = 0;
        while(aIndex >= 0 || bIndex >= 0){
            int cur = (aIndex >= 0 ? a[aIndex--]-'0':0) + (bIndex >= 0 ? b[bIndex--]-'0':0) + carry;
            res = to_string(cur % 2) + res;
            carry = cur / 2;

        }
        return carry == 1 ? "1" + res : res;
    }
};
