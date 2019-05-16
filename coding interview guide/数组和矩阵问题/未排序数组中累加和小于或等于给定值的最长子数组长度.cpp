//
// Created by 钟奇龙 on 2019-05-16.
//

#include <iostream>
#include <vector>
using namespace std;
int getLessIndex(vector<int> helper,int target){
    int left = 0;
    int right = helper.size()-1;
    int res = -1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(helper[mid] >= target){
            res = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return res;
}
int getMaxLength(vector<int> arr,int target){
    if(arr.size() == 0) return 0;
    int sum = 0;
    vector<int> helpArr(arr.size()+1,0);
    helpArr[0] = arr[0];
    for(int i=0; i<arr.size(); ++i){
        sum += arr[i];
        helpArr[i+1] = max(sum,helpArr[i]);
    }
    sum = 0;
    int maxLength = 0;
    int pre = 0;
    for(int i=0 ;i<arr.size(); ++i){
        sum += arr[i];
        pre = getLessIndex(helpArr,sum - target);
        maxLength = max(maxLength,pre == -1 ? 0:(i-pre+1));
    }
    return maxLength;
}

int main(){
    cout<<getMaxLength({3,-2,-4,0,6},-2)<<endl;

    return 0;
}