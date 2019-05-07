//
// Created by 钟奇龙 on 2019-05-07.
//
#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int> mark,int curRow,int curCol){
    for(int k=0; k<curRow; ++k){
        if(mark[k] == curCol || abs(curRow-k) == abs(mark[k]-curCol)){
            return false;
        }
    }
    return true;
}
int helper(vector<int> mark,int curRow,int n){
    if(curRow == n) return 1;
    int res = 0;
    for(int col=0; col < n; ++col){
        if(isValid(mark,curRow,col)){
            mark[curRow] = col;
            res += helper(mark,curRow+1,n);
        }
    }
    return res;
}
int NQueensCount(int n){
    if(n <= 0) return 0;
    vector<int> mark(n);
    return helper(mark,0,n);
}

int main(){
    cout<<NQueensCount(8)<<endl;

    return 0;
}