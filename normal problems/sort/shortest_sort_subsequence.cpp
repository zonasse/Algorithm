#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int shortest_sort_subsequence(vector<int> &nums){
        if(nums.empty() || nums.size() < 2){
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        int max = nums[0];
        int min = nums[right];
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] > max){
                max = nums[i];
            }else{
                right = i;
            }
        }
        for(int i=nums.size()-1; i>=0; --i){
            if(nums[i] < min){
                min = nums[i];
            }else{
                left = i;
            }
        }
        if(left == right){
            return 0;
        }
        return right - left + 1;
    }

};

int main(){
    int arr[] = {1,4,6,5,9,10};
    vector<int> nums(arr,arr+6);
    Solution s;
    printf("%d\n",s.shortest_sort_subsequence(nums));

    return 0;
}
