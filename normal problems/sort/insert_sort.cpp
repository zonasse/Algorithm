#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void insert_sort(vector<int> &nums){
        for(int i=1; i<nums.size(); ++i){
            for(int j=i; j>0 && nums[j] < nums[j-1]; --j){
                int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
        }
    }

};

int main(){
    int arr[8] = {3,5,2,1,8,7,4,10};
    vector<int> nums(arr,arr+8);
    Solution s;
    s.insert_sort(nums);
    for(int i=0; i<nums.size(); ++i){
        printf("%d ",nums[i]);
    }
    return 0;
}
