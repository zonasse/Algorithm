class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        int carry = 0;
        for(int i=n; i>=0; --i){
            digits[i] += 1;
            carry = digits[i]/10;
            digits[i] %= 10;
            if(carry == 0) break;
        }
        if(carry){
            digits.insert(digits.begin(),carry);
        }
        return digits;

    }
};
