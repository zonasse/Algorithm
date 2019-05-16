//
// Created by 钟奇龙 on 2019-05-12.
//

#include <vector>
#include <iostream>
using namespace std;

void setNumIntoSupport(vector<int> &support,int num,int k){
    vector<int> temp(32,0);
    int index = 0;
    while(num){
        temp[index++] = num%k;
        num/=k;
    }
    for(int i=0; i<support.size(); ++i){
        support[i] = (support[i] + temp[i])%k;
    }
}
int getOnceNum(vector<int> arr,int k){
    vector<int> support(32,0);
    for(int i=0; i<arr.size(); ++i){
        setNumIntoSupport(support,arr[i],k);
    }
    //将support数组转为10进制数
    int res = 0;
    for(int i=support.size()-1; i>=0; --i){
            res = res * k + support[i];
    }
    return res;
}

int main(){
    vector<int> arr = {1,1,1,4,2,2,4,3,3,3,4,2,5};
    cout<<getOnceNum(arr,3)<<endl;
    return 0;
}