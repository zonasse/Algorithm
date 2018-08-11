/*
 *  快速排序
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void quick_sort(vector<int> &nums){
        if(nums.empty() || nums.size() < 2){
            return;
        }
        _quick_sort(nums,0,nums.size()-1);
        //_quick_sort_three(nums,0,nums.size()-1);
    }


private:
    //普通快排
    void _quick_sort(vector<int> &nums,int left,int right){
        if(left >= right){
            return;
        }
        int mid = _partition(nums,left,right);
        _quick_sort(nums,left,mid-1);
        _quick_sort(nums,mid+1,right);
    }
    int _partition(vector<int> &nums,int left,int right){
        int i = left,j = right+1;
        int pivot = nums[left];
        while(true){
            while(nums[++i] < pivot) if(i >= right) break;
            while(nums[--j] > pivot) if(j <= left) break;
            if(i >= j){
                break;
            }
            _swap(nums[i],nums[j]);
        }
        _swap(nums[left],nums[j]);
        return j;
    }
    void _swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    //方法2:三向切分
    void _quick_sort_three(vector<int> &nums,int left,int right){
        if(left >= right){
            return;
        }
        int lt=left;
        int i = left+1;
        int gt = right;
        int pivot = nums[left];
        while(i <= gt){
            if(nums[i] > pivot){
                _swap(nums[i],nums[gt]);
                gt--;
            }else if(nums[i] < pivot){
                _swap(nums[i],nums[lt]);
                i++;
                lt++;
            }else{
                i++;
            }
        }
        _quick_sort_three(nums,left,lt-1);
        _quick_sort_three(nums,gt+1,right);
    }
};

int main(){
    //int arr[8] = {3,5,2,1,8,7,4,10};
    int arr[8] = {1,3,2,3,1,2,3,2};

    vector<int> nums(arr,arr+8);
    Solution s;
    s.quick_sort(nums);
    for(int i=0; i<nums.size(); ++i){
        printf("%d ",nums[i]);
    }
    return 0;
}
