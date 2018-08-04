#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int get_less_index(vector<int> &nums){
        if(nums.empty()){
            return -1;
        }
        if(nums.size() == 1 || nums[0] < nums[1]){
            return 0;
        }
        int n = nums.size();
        if(nums[n-1] < nums[n-2]){
            return n-1;
        }
        int left = 1;
        int right = n-2;
        int mid = 0;
        while(left <= right){
            mid = left+(right-left)/2;
            int A = nums[mid];
            int B = nums[mid-1];
            int C = nums[mid+1];
            if(A > B){
                right = mid-1;
            }else if(A > C){
                left = mid+1;
            }else{
                return mid;
            }
        }
        return left;
    }
};

int main(){
    int arr[] = {3,1,2,4};
    vector<int> nums(arr,arr+4);
    Solution handle;
    printf("%d\n",handle.get_less_index(nums));
    return 0;
}
