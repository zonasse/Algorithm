class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res;
        /*
         * 从nums1中取i个数，从nums2中取k-i个数
         * 0 <= i <= m , 0 <= k-i <= n
         */
        for(int i=max(k-n,0); i<=min(k,m); ++i){
            res = max(res,mergeTwoVec(getMaxVec(nums1,i),getMaxVec(nums2,k-i)));
        }
        return res;
    }
    vector<int> getMaxVec(vector<int> &nums,int k){
        vector<int> res;
        int drop = nums.size()-k;
        for(int num : nums){
            while(drop && res.size() && res.back() < num){
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }
    vector<int> mergeTwoVec(vector<int> vec1,vector<int> vec2){
        vector<int> res;
        while(vec1.size() + vec2.size()){
            vector<int> &temp = vec1 > vec2 ? vec1:vec2;
            res.push_back(temp[0]);
            temp.erase(temp.begin());
        }
        return res;
    }
};
