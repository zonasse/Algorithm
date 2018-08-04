#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int fast_n_square(int k,int n){
        if(k == 0){
            return 0;
        }
        if(k == 1 || n == 0){
            return 1;
        }
        long modNum = 1000000007;
        long res = 1;
        long temp = k;
        for(; n > 0; n >>= 1){
            if(n & 1 != 0){
                res *= temp;
            }
            temp = (temp*temp) % modNum;
            res = res % modNum;
        }
        return (int)res;
    }


};

int main(){
    Solution handle;
    printf("%d\n",handle.fast_n_square(10,13));
    return 0;
}
