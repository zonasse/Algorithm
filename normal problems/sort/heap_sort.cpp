/*
 *  堆排序
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void heap_sort(vector<int> &nums){
        if(nums.empty() || nums.size() < 2){
            return;
        }
        //1.½¨¶Ñ
        for(int i=0; i<nums.size(); ++i){
            _heapInsert(nums,i);
        }
        int size = nums.size();
        _swap(nums[--size],nums[0]);
        while(size > 0){
            _heapify(nums,0,size);
            _swap(nums[--size],nums[0]);
        }

    }
private:
    void _swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void _heapInsert(vector<int> &nums,int index){
        while(nums[index] > nums[(index-1)/2]){
            _swap(nums[index],nums[(index-1)/2]);
            index = (index-1)/2;
        }
    }
    void _heapify(vector<int> &nums,int index,int size){
        int left = index*2+1;
        while(left < size){
            int largerIndex = left+1 <size && nums[left+1]>nums[left]? left+1:left;
            largerIndex = nums[index] > nums[largerIndex] ? index:largerIndex;
            if(largerIndex == index){
                break;
            }
            _swap(nums[largerIndex],nums[index]);
            index = largerIndex;
            left = index*2+1;
        }
    }
};

int main(){
    int arr[8] = {3,5,2,1,8,7,4,10};
    vector<int> nums(arr,arr+8);
    Solution s;
    s.heap_sort(nums);
    for(int i=0; i<nums.size(); ++i){
        printf("%d ",nums[i]);
    }
    return 0;
}
