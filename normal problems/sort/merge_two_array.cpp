/*
 *  合并两个排序数组
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void merge_two_array(int arr1[],int len1,int arr2[],int len2,int maxLen){
        if(arr1 == NULL || arr2 == NULL || len1 + len2 > maxLen){
            return;
        }
        int end = len1 + len2 - 1;
        int end1 = len1-1;
        int end2 = len2-1;
        while(end){
            if(arr1[end1] > arr2[end2]){
                arr1[end] = arr1[end1--];
            }else{
                arr1[end] = arr2[end2--];
            }
            end--;
        }
    }


};
int main(){
    int arr1[10] = {1,3,4,5,7};
    int arr2[5] = {2,4,6,8,10};
    Solution s;
    s.merge_two_array(arr1,5,arr2,5,10);
    for(int i=0; i<10; ++i){
        printf("%d\n",arr1[i]);
    }
    return 0;
}
