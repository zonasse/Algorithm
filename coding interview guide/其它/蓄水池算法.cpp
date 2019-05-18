//
// Created by 钟奇龙 on 2019-05-18.
//
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
int random(int n){
    return rand()%n + 1;
}
vector<int> getKNumsRand(int k,int N){
    if(N < 1 || k < 1) return {};
    vector<int> bag(min(k,N));
    for(int i=0; i<k; ++i){
        bag[i] = i+1;
    }
    for(int i=k+1; i<=N; ++i){
        if(random(i) <= k){
            bag[random(k)-1] = i;
        }
    }
    return bag;
}

int main(){
    srand((unsigned)time(0));
    vector<int> bag = getKNumsRand(5,10);

    return 0;
}