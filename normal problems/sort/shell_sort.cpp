/*
 *  Ï£¶ûÅÅÐò
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void shell_sort(vector<int> &nums){
        int h = 1;
        while(h < nums.size() / 3){
            h = h * 3 + 1;
        }
        while(h >= 1){
            for(int i=h; i<nums.size(); ++i){
                for(int j = i; j >= h && nums[j] < nums[j-h]; j-=h){
                    int temp = nums[j];
                    nums[j] = nums[j-h];
                    nums[j-h] = temp;
                }
            }
            h /= 3;
        }

    }

};

int main(){
    int arr[8] = {3,5,2,1,8,7,4,10};
    vector<int> nums(arr,arr+8);
    Solution s;
    s.shell_sort(nums);
    for(int i=0; i<nums.size(); ++i){
        printf("%d ",nums[i]);
    }
    return 0;
}
