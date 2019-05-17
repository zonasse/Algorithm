//
// Created by 钟奇龙 on 2019-05-17.
//

#include <vector>
#include <iostream>
using namespace std;
/*
 * 原问题
 */
void leftUnique(vector<int> &arr){
    if(arr.size() < 2) return;
    int left = 0;
    int right = 1;
    while(right < arr.size()){
        if(arr[right] != arr[left]){
            swap(arr[left+1],arr[right]);
            left++;
        }
        right++;
    }
}
/*
 * 荷兰国旗问题
 */
void sortForThreeColors(vector<int> &arr){
    if(arr.size() < 2) return;
    int left = -1;
    int right = arr.size();
    int index = 0;
    while(index < right){
        if(arr[index] == 0){
            swap(arr[index++],arr[++left]);
        }else if(arr[index] == 2){
            swap(arr[index],arr[--right]);
        }else{
            ++index;
        }
    }
}
int main(){
//    vector<int> arr = {1,2,2,2,3,3,4,5,6,6,7,7,8,8,8,9};
//    leftUnique(arr);
    vector<int> arr = {1,0,2,2,1,0,0,1,2,0};
    sortForThreeColors(arr);

}