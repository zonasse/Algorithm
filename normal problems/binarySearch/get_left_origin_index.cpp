#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int get_left_origin_index(vector<int> &nums){
        if(nums.empty()){
            return -1;
        }
        int left = 0;
        int right = nums.size()-1;
        if(nums[left] > right || nums[right] < left){
            return -1;
        }
        int res = -1;
        while(left <= right){
            if(nums[left] > left || nums[right] < right){
                break;
            }
            int mid = left + (right-left)/2;
            if(nums[mid] > mid){
                right = mid-1;
            }else if(nums[mid] < mid){
                left = mid+1;
            }else{
                res = mid;
                right = mid-1;
            }


        }
        return res;
    }


};

int main(){
    int arr[] = {-1,0,2,3};
    vector<int> nums(arr,arr+4);
    Solution handle;
    printf("%d\n",handle. get_left_origin_index(nums));

    return 0;
}
