class Solution {
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
