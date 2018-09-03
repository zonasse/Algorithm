class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int num : nums){
            sum += num;
        }
        return 0.5 * (n+1) * n - sum;
    }
};
