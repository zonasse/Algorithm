#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    enum Status{valid = 0,invalid};
    int status;
    int StrToInt(string str) {
        status = invalid;
        long long num = 0;
        int index = 0;
        if(str.size() > 0){
            bool minus = false;
            if(str[index] == '+'){
                index++;
            }else if(str[index] == '-'){
                index++;
                minus = true;
            }
            while(index < str.size()){
                if(str[index] >= '0' && str[index] <= '9'){
                    int flag = minus? -1:1;
                    num = num*10+flag*(str[index] - '0');
                    if((minus == false && num > 0x7fffffff)|| (minus == true && num < (signed int)0x80000000)){
                        num = 0;
                        break;
                    }
                    index++;
                }else{
                    num = 0;
                    break;
                }
            }

        }
        if(index == str.size()-1){
            status = valid;
        }
        return num;
    }
};
int main(){
    string s = "-123";
    Solution handle;
    printf("%d\n",handle.StrToInt(s));
    return 0;
}
