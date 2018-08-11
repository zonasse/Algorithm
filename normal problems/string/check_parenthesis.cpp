/*
 *  ≈–∂œ∫œ∑®¿®∫≈–Ú¡–
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool check_parenthesis(string str){
        if(str.empty()) return false;
        int num = 0;
        for(int i=0; i<str.size(); ++i){
            if(str[i] == '('){
                num++;
            }else if(str[i] == ')'){
                num--;
            }else{
                if(num == 0){
                    return false;
                }
            }

        }
        if(num != 0){
            return false;
        }
        return true;

    }


};
int main(){
    //string str = "(()())";
    string str = "()a()";

    Solution s;
    printf("%d\n",s.check_parenthesis(str));
    return 0;
}
