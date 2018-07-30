#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void bubble_sort(vector<int> &nums){
        for(int i = 0; i<nums.size(); ++i){
            for(int j = i + 1; j<nums.size() ; ++j){
                if(nums[j] < nums[i]){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }

    }


};

int main(){
    int arr[8] = {3,5,2,1,8,7,4,10};
    vector<int> nums(arr,arr+8);
    Solution s;
    s.bubble_sort(nums);
    for(int i=0; i<nums.size(); ++i){
        printf("%d ",nums[i]);
    }
    return 0;
}
