/*
 *  πÈ≤¢≈≈–Ú
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void merge_sort(vector<int> &nums){
        if(nums.empty() || nums.size() < 2 ){
            return;
        }
        _mergeSort(nums,0,nums.size()-1);
    }
private:
    void _mergeSort(vector<int> &nums,int left,int right){
        if(left >= right){
            return;
        }
        int mid = left + (right-left)/2;
        _mergeSort(nums,left,mid);
        _mergeSort(nums,mid+1,right);
        _merge(nums,left,mid,right);
    }
    void _merge(vector<int> &nums,int left,int mid,int right){
        vector<int> support;
        int index1 = left;
        int index2 = mid+1;
        while(index1 <= mid && index2 <= right){
            if(nums[index1] < nums[index2]){
                support.push_back(nums[index1++]);
            }else{
                support.push_back(nums[index2++]);
            }
        }
        while(index1 <= mid){
            support.push_back(nums[index1++]);
        }
        while(index2 <= right){
            support.push_back(nums[index2++]);
        }
        for(int i=0; i<support.size(); ++i){
            nums[left+i] = support[i];
        }
    }
};

int main(){
    int arr[8] = {3,5,2,1,8,7,4,10};
    vector<int> nums(arr,arr+8);
    Solution s;
    s.merge_sort(nums);
    for(int i=0; i<nums.size(); ++i){
        printf("%d ",nums[i]);
    }
    return 0;
}
