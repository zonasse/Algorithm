class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        int n1 = num1.size();
        int n2 = num2.size();
        int k = n1 + n2 - 2;
        vector<int> arr(n1+n2,0);
        for(int i=0; i<n1; ++i){
            for(int j=0; j<n2; ++j){
                arr[k-i-j] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        int carry = 0;
        for(int i=0; i<n1+n2; ++i){
            arr[i] += carry;
            carry = arr[i] / 10;
            arr[i] %= 10;
        }
        int i = n1 + n2 -1;
        while(arr[i] == 0) --i;
        if(i < 0) return "0";
        while(i >= 0) res.push_back(arr[i--]+'0');
        return res;
    }
};
