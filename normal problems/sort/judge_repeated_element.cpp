/*
 *  判断数组是否有重复元素
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool judge_repeated_element(vector<int> nums){
        if(nums.empty() || nums.size() < 2){
            return false;
        }
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1; ++i){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};
int main(){
    int arr[] = {2,5,7,32,1,7};
    vector<int> nums(arr,arr+6);
    Solution s;
    printf("%s\n",s.judge_repeated_element(nums) ? "YES":"NO");
    nums[5] = 8;
    printf("%s\n",s.judge_repeated_element(nums) ? "YES":"NO");

    return 0;
}
