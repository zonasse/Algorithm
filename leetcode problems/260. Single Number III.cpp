class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int eo = 0,eoHasOne = 0;
        for(auto &a :nums){
            eo ^= a;
        }
        int rightOne = eo & (~eo + 1);
        for(auto &a : nums){
            if((a & rightOne) != 0){
                eoHasOne ^= a;
            }
        }
        return {eoHasOne,eo ^ eoHasOne};
    }
};
