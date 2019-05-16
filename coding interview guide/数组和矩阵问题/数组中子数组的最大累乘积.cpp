//
// Created by 钟奇龙 on 2019-05-16.
//
#include <iostream>
#include <vector>
using namespace std;

double maxProduct(vector<double> arr){
    if(arr.size() == 0) return 0;
    double preMax = arr[0];
    double preMin = arr[0];
    double maxMulti = arr[0];
    for(int i=1; i<arr.size(); ++i){
        double maxEnd = preMax * arr[i];
        double minEnd = preMin * arr[i];
        preMax = max(max(maxEnd,minEnd),arr[i]);
        preMin = min(min(maxEnd,minEnd),arr[i]);
        maxMulti = max(maxMulti,preMax);
    }
    return maxMulti;
}

int main(){
    vector<double> arr = {-2.5,4,0,3,0.5,8,-1};
    cout<<maxProduct(arr)<<endl;
    return 0;
}
