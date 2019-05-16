//
// Created by 钟奇龙 on 2019-05-16.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int getMaxLength(vector<int> arr,int target){
    if(arr.size() == 0){
        return 0;
    }
    int sum = 0;
    map<int,int> m;
    m[0] = -1;
    int maxLength = 0;
    for(int i=0; i<arr.size(); ++i){
        sum += arr[i];
        if(m.find(sum - target) != m.end()){
            maxLength = max(maxLength,i-m[sum-target]);
        }
        if(m.find(sum) == m.end()){
            m[sum] = i;
        }
    }
    return maxLength;
}
int main(){
    cout<<getMaxLength({-8,-4,-3,0,1,2,2,8,9},10)<<endl;
//    cout<<getMaxLength({1,2,3,3},6)<<endl;

    return 0;
}