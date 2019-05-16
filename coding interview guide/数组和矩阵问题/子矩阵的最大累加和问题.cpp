//
// Created by 钟奇龙 on 2019-05-16.
//
#include <vector>
#include <iostream>
using namespace std;

int maxSum(vector<vector<int> > matrix){
    if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int maxSum = 0;
    for(int i=0; i<matrix.size(); ++i){
        vector<int> s(matrix[0].size());
        for(int j=i; j<matrix.size(); ++j){
            int curSum = 0;
            for(int k=0; k<matrix[0].size(); ++k){
                s[k] += matrix[j][k];
                curSum += s[k];
                maxSum = max(maxSum,curSum);
                if(curSum < 0){
                    curSum = 0;
                }
            }
        }
    }
    return maxSum;
}

int main(){
    vector<vector<int> > arr = {{-90,48,78},{64,-40,64},{-81,-7,66}};
    cout<<maxSum(arr)<<endl;
    return 0;
}
