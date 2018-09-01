class Solution {
public:
    int calculate(string s) {
        enum STATE{
            STATE_BEGIN = 0,
            STATE_NUMBER = 1,
            STATE_OPERATOR = 2
        };
        int number = 0;
        STATE state = STATE_BEGIN;
        bool computeFlag = false;
        stack<int> number_stack;
        stack<char> operator_stack;

        for(int i=0; i<s.size(); ++i){
            if(s[i] == ' ') continue;
            switch(state){
                case STATE_BEGIN:{
                    if(s[i] >= '0' && s[i] <= '9'){
                        state = STATE_NUMBER;
                    }else{
                        state = STATE_OPERATOR;
                    }
                    i--;
                }
                break;
                case STATE_NUMBER:{
                    if(s[i] >= '0' && s[i] <= '9'){
                        number = number * 10 + s[i] - '0';
                    }else{
                        number_stack.push(number);
                        number = 0;
                        if(computeFlag == true){
                            compute(number_stack,operator_stack);
                        }
                        state = STATE_OPERATOR;
                        i--;
                    }
                }
                break;
                case STATE_OPERATOR:{
                    if(s[i] == '+' || s[i] == '-'){
                        operator_stack.push(s[i]);
                        computeFlag = true;
                    }else if(s[i] == '('){
                        computeFlag = false;
                        state = STATE_NUMBER;
                    }else if(s[i] == ')'){
                        compute(number_stack,operator_stack);
                    }else{
                        state = STATE_NUMBER;
                        i--;
                    }
                }
                break;
            }
        }
        if(number){
            number_stack.push(number);
            compute(number_stack,operator_stack);
        }
        if(!number && number_stack.empty()){
            return 0;
        }

        return number_stack.top();
    }
    void compute(stack<int> &number_stack,stack<char> &operator_stack){
        if(number_stack.size() < 2) return ;
        int number2 = number_stack.top();
        number_stack.pop();
        int number1 = number_stack.top();
        number_stack.pop();
        if(operator_stack.top() == '+'){
            number_stack.push(number1 + number2);
        }else{
            number_stack.push(number1 - number2);
        }
        operator_stack.pop();
    }
};
