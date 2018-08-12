class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int index = 0;
        while(str[index] == ' ') index++;
        if(str[index] != '+' && str[index] != '-' && !(str[index] >= '0' && str[index] <= '9')){
            return 0;
        }
        bool positive = true;
        if(str[index] == '+' || str[index] == '-'){
            positive = str[index] == '+' ? true:false;
            index++;
        }
        long res = 0;
        while(str[index] >= '0' && str[index] <= '9'){
            res = res*10 + str[index] - '0';
            if(abs(res) > INT_MAX){
                return positive? INT_MAX:INT_MIN;
            }
            index++;
        }
        return positive ? res:res*(-1);
    }
};
