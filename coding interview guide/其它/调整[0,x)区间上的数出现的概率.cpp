//
// Created by 钟奇龙 on 2019-05-19.
//

#include <iostream>
using namespace std;
/*
 * 随机生成[0,1)区间的数
 */
double randomZeroToOne(){
    return (rand()%100) / (double)101;
}
double randXPowerK(int k){
    if(k < 1) return 0;
    double res = -1;
    for(int i=0; i<k; ++i){
        res = max(res,randomZeroToOne());
    }
    return res;
}

int main(){
    srand(time(0));
    cout<<randXPowerK(5)<<endl;
}