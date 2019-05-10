//
// Created by 钟奇龙 on 2019-05-10.
//
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int getOperatorLevel(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}
int calculateTwoNums(int num1,int num2,char op){
    switch (op){
        case '+':
            return num1+num2;
        case '-':
            return num1-num2;
        case '*':
            return num1*num2;
        case '/':
            return num1/num2;
    }
}
vector<int> helper(string s,int index){
    int curNum = 0;
    stack<int> digitStack;
    stack<char> operatorStack;
    bool positive = true;
    if(index < s.size() && s[index] == '-'){
        positive = false;
        index++;
    }
    while(index < s.size() && s[index] != ')'){
        if(s[index] >= '0' && s[index] <= '9'){//如果为数字
            while(index < s.size() && s[index] >= '0' && s[index] <= '9'){
                if(positive == false){
                    curNum = curNum * 10 - (s[index++] - '0');
                }else{
                    curNum = curNum * 10 + (s[index++] - '0');
                }
            }
            digitStack.push(curNum);
            positive = true;
            curNum = 0;
        }else if(s[index] != '('){//如果为符号
            if(operatorStack.empty() == true){
                operatorStack.push(s[index]);
            }else{
                while(operatorStack.empty() == false && getOperatorLevel(s[index]) <= getOperatorLevel(operatorStack.top())){
                    char topOperator = operatorStack.top();
                    operatorStack.pop();
                    int num2 = digitStack.top();
                    digitStack.pop();
                    int num1 = digitStack.top();
                    digitStack.pop();
                    digitStack.push(calculateTwoNums(num1,num2,topOperator));
                }
                operatorStack.push(s[index]);
            }
            index++;
        }else{//为左括号，进入下一层递归
            vector<int> next = helper(s,index+1);
            digitStack.push(next[0]);
            index = next[1]+1;

        }
    }
    while(digitStack.size() > 1){
        int num2 = digitStack.top();
        digitStack.pop();
        int num1 = digitStack.top();
        digitStack.pop();
        digitStack.push(calculateTwoNums(num1,num2,operatorStack.top()));
        operatorStack.pop();
    }

    return {digitStack.empty() == false ? digitStack.top():0,index};
}
int calculateString(string s){
    return helper(s,0)[0];
}


int main(){
    cout<<calculateString("-48*((70-65)-43)+8*1")<<endl;
    cout<<calculateString("5")<<endl;

    return 0;
}