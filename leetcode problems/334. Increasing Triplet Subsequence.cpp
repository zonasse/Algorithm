class Solution1 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1 = INT_MAX, num2 = INT_MAX;
        for(int num : nums){
            if(num1 >= num){
                num1 = num;
            }else if(num2 >= num){
                num2 = num;
            }else{
                return true;
            }
        }
        return false;
    }
};
class Solution2 {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int n = nums.size();
         vector<int> forword(n,nums[0]),backword(n,nums[n-1]);
        for(int i=1; i<n; ++i){
            forword[i] = min(forword[i-1],nums[i]);
        }
        for(int i=n-2; i>=0; --i){
            backword[i] = max(backword[i+1],nums[i]);
        }
        for(int i=0; i<n; ++i){
            if(forword[i] < nums[i] && nums[i] < backword[i]){
                return true;
            }
        }
        return false;
    }
};
