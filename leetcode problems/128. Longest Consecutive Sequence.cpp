class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        map<int,int> M;
        int maxLen = 1;
        for(int i=0; i<nums.size(); ++i){
            if(M.find(nums[i]) != M.end()) continue;
            M[nums[i]] = 1;
            if(M.find(nums[i] - 1) != M.end()){
                maxLen = max(maxLen,merge(M,nums[i]-1,nums[i]));
            }
            if(M.find(nums[i] + 1) != M.end()){
                maxLen = max(maxLen,merge(M,nums[i],nums[i] + 1));
            }
        }
        return maxLen;
    }
    int merge(map<int,int> &M,int less,int more){
        int leftNum = less - M[less] + 1;//◊Û¿©
        int rightNum = more + M[more] - 1;//”“¿©
        int len = rightNum - leftNum + 1;
        M[leftNum] = len;
        M[rightNum] = len;
        return len;
    }
};
