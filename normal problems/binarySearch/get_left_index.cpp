#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int get_left_index(vector<int> &nums,int target){
        if(nums.empty()){
            return -1;
        }
        int left = 0;
        int right = nums.size()-1;
        int res = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                res = mid;
                right = mid-1;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return res;
    }


};

int main(){
    int arr[] = {1,2,3,3,4,9,10,13};
    vector<int> nums(arr,arr+8);
    Solution handle;
    printf("%d\n",handle.get_left_index(nums,3));

    return 0;
}
