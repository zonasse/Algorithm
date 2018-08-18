class Solution {
public:
    bool isNumber(string s) {
        enum InputType{
            INVALID,SPACE,SIGN,DOT,E,DIGIT,LEN
        };
        int trans[][LEN] = {
            {-1,0,1,2,-1,3},
            {-1,-1,-1,2,-1,3},
            {-1,-1,-1,-1,-1,4},
            {-1,5,-1,4,6,3},
            {-1,5,-1,-1,6,4},
            {-1,5,-1,-1,-1,-1},
            {-1,-1,7,-1,-1,8},
            {-1,-1,-1,-1,-1,8},
            {-1,5,-1,-1,-1,8}
        };
        int status = 0;
        for(int i=0; i<s.size(); ++i){
            InputType input;
            if(s[i] == ' '){
                input = SPACE;
            }else if(s[i] == '+' || s[i] == '-'){
                input = SIGN;
            }else if(s[i] == '.'){
                input = DOT;
            }else if(s[i] == 'e' || s[i] == 'E'){
                input = E;
            }else if(s[i] >= '0' && s[i] <= '9'){
                input = DIGIT;
            }else{
                input = INVALID;
            }
            status = trans[status][input];
            if(status == -1){
                return false;
            }
        }
        return status == 3 || status == 4 || status == 5 || status == 8;
    }
};
