//
// Created by 钟奇龙 on 2019-05-16.
//

#include <vector>
#include <iostream>
using namespace std;
/*
 * 打印二元组
 */
void printUniquePair(vector<int> arr,int target){
    int left = 0;
    int right = arr.size()-1;
    while(left < right){
        if(arr[left] + arr[right] == target){
            if(left == 0 || arr[left] != arr[left-1]){
                cout<<"first: "<<arr[left]<<" second: "<<arr[right]<<endl;
            }
            left++;
            right--;
        }else if(arr[left] + arr[right] < target){
            left++;
        }else{
            right--;
        }
    }
}
/*
 * 打印三元组
 */
void printRest(vector<int> arr,int front,int left,int right,int target){
    while(left < right){
        if(arr[left] + arr[right] == target){
            if(left == front+1 || arr[left] != arr[left-1]){
                cout<<"first: "<<arr[front]<<" second: "<<arr[left]<<" third: "<<arr[right]<<endl;
            }
            left++;
            right--;
        }else if(arr[left] + arr[right] < target){
            left++;
        }else{
            right--;
        }
    }
}

void printUniqueTriad(vector<int> arr,int target){
    if(arr.size() < 3) return;
    for(int i=0; i<arr.size()-2; ++i){
        if(i == 0 || arr[i] != arr[i-1]){
            printRest(arr,i,i+1,arr.size()-1,target-arr[i]);
        }
    }
}

int main(){
//    printUniquePair({-8,-4,-3,0,1,2,2,4,5,8,9},10);
    printUniqueTriad({-8,-4,-3,0,1,2,2,4,5,8,9},10);
    return 0;
}