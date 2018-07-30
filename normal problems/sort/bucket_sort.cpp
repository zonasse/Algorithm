#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void bucket_sort(vector<int> &nums){
        if(nums.empty() || nums.size() < 2){
            return;
        }
        int big = -0x7fffffff;
        for(int i=0; i<nums.size(); ++i){
            big = max(big,nums[i]);
        }
        vector<int> temp(big+1,0);
        for(int i=0; i<nums.size(); ++i){
            temp[nums[i]]++;
        }
        nums.clear();
        for(int i=0; i<temp.size(); ++i){
            while(temp[i]--){
                nums.push_back(i);
            }
        }
    }
};

int main()
{
    int arr[] = {3,65,34,1,6,4,73};
    vector<int> nums(arr,arr+7);
    Solution s;
    s.bucket_sort(nums);
    for(int i=0; i<nums.size(); ++i){
        printf("%d\n",nums[i]);
    }
    return 0;
}
