#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {

        int number = 0;
        stack<int> number_stack;
        stack<char> operator_stack;
        map<char,int> M;
        M['+'] = 1;
        M['-'] = 1;
        M['*'] = 2;
        M['/'] = 2;
        for(int i=0 ;i<s.size(); ++i){
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9'){
                number = number * 10 + s[i] - '0';
            }else{
                number_stack.push(number);
                number = 0;
                if(operator_stack.empty() || M[s[i]] > M[operator_stack.top()]){
                    operator_stack.push(s[i]);
                }else{
                    while(!operator_stack.empty() && M[s[i]] <= M[operator_stack.top()]){
                        cal(number_stack,operator_stack);
                    }
                    operator_stack.push(s[i]);
                }
            }
        }
        if(number>= 0) number_stack.push(number);
        while(number_stack.size() > 1 && !operator_stack.empty()){
            cal(number_stack,operator_stack);
        }

        return number_stack.top();
    }
    void cal(stack<int> &number_stack,stack<char> &operator_stack){
        int number2 = number_stack.top();
        number_stack.pop();
        int number1 = number_stack.top();
        number_stack.pop();
        char op = operator_stack.top();
        operator_stack.pop();
        int newNum = 0;
        if(op == '+'){
            newNum = number1 + number2;
        }else if(op == '-'){
            newNum = number1 - number2;
        }else if(op == '*'){
            newNum = number1 * number2;
        }else{
            newNum = number1 / number2;
        }
        number_stack.push(newNum);
    }
};

