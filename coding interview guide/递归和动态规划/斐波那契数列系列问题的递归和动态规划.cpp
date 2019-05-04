//
// Created by 钟奇龙 on 2019-05-04.
//
#include <vector>
#include <iostream>
using namespace std;
/*
 * 经典问题  f(1)=1,f(2)=1
 */
vector<vector<int>> matrixMulti(vector<vector<int>> m1,vector<vector<int>> m2){
    vector<vector<int> > res(m1.size(),vector<int>(m2[0].size(),0));
    for(int i=0; i<m1.size(); ++i){
        for(int j=0; j<m2[0].size(); ++j){
            for(int k=0; k<m2.size(); ++k){
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return res;
}
vector<vector<int> > powerMatrixMulti(vector<vector<int> > matrix,int times){
    vector<vector<int> > res(matrix.size(),vector<int>(matrix[0].size(),0));
    for(int i=0; i<matrix.size(); ++i){
        res[i][i] = 1;
    }
    vector<vector<int> > temp = matrix;
    for(; times != 0; times>>=1){
        if((times & 1) != 0){
            res = matrixMulti(res,temp);
        }
        temp = matrixMulti(temp,temp);
    }
    return res;
}

int fabonacci(int n){
    if(n < 1) return 0;
    if(n == 1 || n == 2) return 1;
    vector<vector<int> > matrix = {{1,1},{1,0}};
    vector<vector<int> > res = powerMatrixMulti(matrix,n-2);
    return res[0][0] + res[1][0];
}
/*
 * 跳楼梯，f(1) = 1,f(2) = 2
 */
int fabonacci2(int n){
    if(n < 1) return 0;
    if(n <= 2) return n;
    vector<vector<int> > matrix = {{1,1},{1,0}};
    vector<vector<int> > res = powerMatrixMulti(matrix,n-2);
    return 2*res[0][0] + res[1][0];
}
/*
 * 生小牛问题,f(n) = f(n-1) + f(n-3),f(1)=1,f(2)=2,f(3)=3
 */
int fabonacci3(int n){
    if(n < 1) return 0;
    if(n <= 3) return n;
    int f1=1;
    int f2=2;
    int f3=3;
    int res=0;
    for(int i=4; i<=n; ++i){
        res = f1+f3;
        f1=f2;
        f2=f3;
        f3=res;
    }
    return res;
}
int fabonacci3ByMatrix(int n){
    if(n < 1) return 0;
    if(n <= 3) return n;
    vector<vector<int> > matrix = {{1,1,0},{0,0,1},{1,0,0}};
    vector<vector<int> > res = powerMatrixMulti(matrix,n-3);
    return 3*res[0][0] + 2*res[1][0] + res[2][0];
}
int main(){
    cout<<fabonacci(7)<<endl;
    cout<<fabonacci2(8)<<endl;
    cout<<fabonacci3(20)<<endl;
    cout<<fabonacci3ByMatrix(20)<<endl;
    return 0;
}