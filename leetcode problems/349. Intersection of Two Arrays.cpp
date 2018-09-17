class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(),nums1.end());
        vector<int> res;
        for(int i=0; i<nums2.size() ; ++i){
            if(s.count(nums2[i])){
                s.erase(nums2[i]);
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(),nums2.end());
        set<int> res;
        for(int a : nums1){
            if(binarySearch(nums2,a)){
                    res.insert(a);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
    bool binarySearch(vector<int> &nums,int val){
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == val){
                return true;
            }else if(nums[mid] > val){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return false;
    }
};
