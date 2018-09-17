class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> M;
        vector<int> res;
        for(int a : nums1) M[a]++;
        for(int a : nums2){
            if(M[a]-- > 0){
                res.push_back(a);
            }
        }
        return res;
    }
};
