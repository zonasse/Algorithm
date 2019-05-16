//
// Created by 钟奇龙 on 2019-05-16.
//
#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int> &arr,int left,int mid,int right){
    vector<int> support(right-left+1);
    int index = 0;
    int l1 = left;
    int l2 = mid+1;
    int sum = 0;
    while(l1 <= mid && l2<=right){
        if(arr[l1] <= arr[l2]){
            sum += arr[l1]*(right-l2+1);
            support[index++] = arr[l1++];
        }else{
            support[index++] = arr[l2++];
        }
    }
    while(l1 <= mid){
        support[index++] = arr[l1++];
    }
    while(l2 <= right){
        support[index++] = arr[l2++];
    }
    for(int i=0; i<support.size(); ++i){
        arr[i+left] = support[i];
    }
    return sum;
}
int helper(vector<int> &arr,int left,int right){
    if(left >= right) return 0;
    int mid = left + (right-left)/2;
    int sum = 0;
    sum += helper(arr,left,mid);
    sum += helper(arr,mid+1,right);
    sum += merge(arr,left,mid,right);
    return sum;
}
int getSmallSum(vector<int> arr){
    if(arr.size() < 2) return 0;
    return helper(arr,0,arr.size()-1);
}

int main(){
    vector<int> arr = {1,3,5,2,4,6};
    cout<<getSmallSum(arr);

    return 0;
}