//
// Created by 钟奇龙 on 2019-05-19.
//
#include <iostream>
#include <vector>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
void printRandomM(vector<int> arr,int m){
    if(arr.size() == 0 || m < 0) return;
    m = min(arr.size(),m);
    int count = 0;
    while(count < m){
        int randomIndex = rand() % (arr.size()-count);
        cout<<arr[randomIndex]<<endl;
        swap(arr[randomIndex],arr[arr.size()-count-1]);
        count++;
    }
}

int main(){
    vector<int> arr = {1,3,4,5,2,6,9,8};
    printRandomM(arr,5);
    return 0;
}
