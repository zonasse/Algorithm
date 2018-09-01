class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m = 0, n =0, cm = 0, cn = 0;
        vector<int> res;
        for(auto & a : nums){
            if(a == m) cm++;
            else if(a == n) cn++;
            else if(cm == 0) m = a,cm = 1;
            else if(cn == 0) n = a,cn = 1;
            else cm--,cn--;
        }
        cm = 0,cn = 0;
        for(auto &a : nums){
            if(a == m) cm++;
            else if(a == n) cn++;
        }
        if(cm > nums.size()/3) res.push_back(m);
        if(cn > nums.size()/3) res.push_back(n);
        return res;
    }
};
