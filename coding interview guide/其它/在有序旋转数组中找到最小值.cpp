//
// Created by 钟奇龙 on 2019-05-20.
//
#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> arr) {
    int left = 0;
    int right = arr.size()-1;
    while(left < right){
        if(arr[left] < arr[right]) break;
        if(arr[left] == arr[left+1]) {left++; continue;}
        if(arr[right] == arr[right-1]) {right--; continue;}
        int mid = left + (right-left)/2;
        if(arr[mid] <= arr[right]){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    return arr[left];
}
//int getMin(vector<int> arr){
//    if(arr.size() == 0) return INT_MIN;
//    int left = 0;
//    int right = arr.size()-1;
//    while(left < right){
//        //只有两个数时退出循环
//        if(left == right-1) break;
//        int mid = left + (right-left)/2;
//        if(arr[left] < arr[right]) return arr[left];
//        if(arr[left] > arr[mid]){
//            right = mid;
//            continue;
//        }
//        if(arr[mid] > arr[right]){
//            left = mid;
//            continue;
//        }
//        //上面条件都不满足说明arr[left]=arr[mid]=arr[right]
//        int index = left+1;
//        while(index < mid){
//            if(arr[index] == arr[left]){
//                index++;
//                continue;
//            }
//            if(arr[index] < arr[left]){
//                return arr[index];
//            }
//            if(arr[index] > arr[left]){
//                right = mid;
//                left = index;
//                break;
//            }
//        }
//        //以上情况皆未出现，说明断点在右半部分
//        left = mid;
//    }
//    return min(arr[left],arr[right]);
//}

int main(){
    cout<<findMin({4,5,6,7,1,2,3})<<endl;

    return 0;
}