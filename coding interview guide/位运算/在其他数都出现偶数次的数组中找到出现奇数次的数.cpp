//
// Created by 钟奇龙 on 2019-05-12.
//
#include <iostream>
#include <vector>
using namespace std;
/*
 * 有一个出现奇数次的数
 */
int printOddTimesNum1(vector<int> arr){
    int res = 0;
    for(int num:arr){
        res ^= num;
    }
    return res;
}
/*
 * 有两个出现奇数次的数
 */
vector<int> printOddTimesNum2(vector<int> arr){
    int a_xor_b = 0;

    for(int num:arr){
        a_xor_b ^= num;
    }
    //找到a_xor_b最右边不为0的位
    int rightOne = a_xor_b & (~a_xor_b + 1);
    int a = 0;
    for(int num:arr){
        if((num & rightOne) != 0){
            a ^= num;
        }
    }
    int b = a_xor_b ^ a;
    return {a,b};
}

int main(){
    cout<<printOddTimesNum1({1,1,2,2,4,4,5,3,5})<<endl;
    vector<int> res = printOddTimesNum2({1,1,2,2,4,4,3,5});
    cout<<res[0]<<" "<<res[1]<<endl;

    return 0;
}
