#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string replace_space(string str,int length){
        int spaceNum = 0;
        for(int i=0; i<length; ++i){
            if(str[i] == ' '){
                spaceNum++;
            }
        }
        int newLength = length + spaceNum*2;
        int indexPre,indexAfter;
        for(indexPre = length-1,indexAfter = newLength-1;indexPre <= indexAfter && indexPre>=0;){
            if(str[indexPre] == ' '){
                str[indexAfter--] = '0';
                str[indexAfter--] = '2';
                str[indexAfter--] = '%';
                indexPre--;
            }else{
                str[indexAfter--] = str[indexPre--];
            }
        }
        return str;

    }
};

int main(){
    string str(1000,' ');
    str = "a b c" + str;
    Solution handle;
    printf("%s\n",handle.replace_space(str,5).c_str());
    return 0;
}
