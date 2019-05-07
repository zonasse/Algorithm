//
// Created by 钟奇龙 on 2019-05-07.
//

#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int> arr){
    if(arr.size() == 0) return 0;
    int jumpSteps = 0;
    int nextLoc = 0;
    int curLoc = 0;
    for(int i=0; i<arr.size(); ++i){
        if(curLoc < i){
            jumpSteps++;
            curLoc = nextLoc;
        }
        nextLoc = max(nextLoc,i+arr[i]);
    }
    return jumpSteps;
}

int main(){
    vector<int> arr = {3,2,3,1,1,4};
    cout<<jump(arr)<<endl;
    return 0;
}