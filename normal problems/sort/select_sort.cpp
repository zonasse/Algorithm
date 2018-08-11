/*
 *  —°‘Ò≈≈–Ú
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void select_sort(vector<int> &nums){
        for(int i = 0; i<nums.size(); ++i){
            int min = i;
            for(int j = i + 1; j<nums.size() ; ++j){
                if(nums[j] < nums[min]){
                    min = j;
                }
            }
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }

    }


};

int main(){
    int arr[8] = {3,5,2,1,8,7,4,10};
    vector<int> nums(arr,arr+8);
    Solution s;
    s.select_sort(nums);
    for(int i=0; i<nums.size(); ++i){
        printf("%d ",nums[i]);
    }
    return 0;
}
