class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0) return res;
        int left = 0;
        int i=0;
        for(; i<nums.size()-1; ++i){
            if(nums[i]+1 != nums[i+1]){
                string s = "";
                if(i == left){
                    s += to_string(nums[i]);
                }else{
                    s += to_string(nums[left]) + "->" + to_string(nums[i]);
                }
                res.push_back(s);
                left = i+1;
            }
        }
        string s = "";
        if(left == i){
            s += to_string(nums[i]);
        }else{
            s += to_string(nums[left]) + "->" + to_string(nums[i]);

        }
        res.push_back(s);
        return res;
    }

};
