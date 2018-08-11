class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size()+nums2.size();
        if(nums1.empty()){
            return findMedian(nums2);
        }
        if(nums2.empty()){
            return findMedian(nums1);
        }
        if(size % 2 == 0){
            int k1 = findKthNum(nums1,nums2,size/2);
            int k2 = findKthNum(nums1,nums2,size/2 + 1);
            return (k1+k2)*0.5;
        }else{
            int k1 = findKthNum(nums1,nums2,size/2 +  1);
            return k1;
        }
    }
    /*
     * 获取单一数组的中位数
     */
    double findMedian(vector<int> &nums){
        int size = nums.size();
        if(size % 2 == 0){
            return (nums[size/2] + nums[size/2 - 1])*0.5;
        }else{
            return nums[size/2];
        }
    }
    /*
     * 获取两个排序数组的第K大的数
     */
    int findKthNum(vector<int> &a1,vector<int> &a2,int kth){
        vector<int> longs = a1.size() >= a2.size() ? a1:a2;
        vector<int> shorts = a1.size() < a2.size() ? a1:a2;
        int lo = longs.size();
        int sh = shorts.size();
        if(kth <= sh){
            return getUpMedian(shorts,0,kth-1,longs,0,kth-1);
        }
        if(kth > lo){
            if(shorts[kth-lo-1] >= longs[lo-1]){
                return shorts[kth-lo-1];
            }
            if(longs[kth-sh-1] >= shorts[sh-1]){
                return longs[kth-sh-1];
            }
            return getUpMedian(shorts,kth-lo,sh-1,longs,kth-sh,lo-1);
        }
        if(longs[kth-sh-1] >= shorts[sh-1]){
            return longs[kth-sh-1];
        }
        return getUpMedian(shorts,0,sh-1,longs,kth-sh,kth-1);
    }

    /*
     * 获取两个大小相等的数组的上中位数
     */
    int getUpMedian(vector<int> &a1,int s1,int e1,vector<int> &a2,int s2,int e2){
        int mid1 = 0;
        int mid2 = 0;
        int offset = 0;
        while(s1 < e1){
            mid1 = s1 + (e1-s1)/2;
            mid2 = s2 + (e2-s2)/2;
            offset = (e1-s1+1) % 2 == 0 ? 1:0;
            if(a1[mid1] > a2[mid2]){
                e1 = mid1;
                s2 = mid2 + offset;
            }else if(a1[mid1] < a2[mid2]){
                s1 = mid1 + offset;
                e2 = mid2;
            }else{
                return a1[mid1];
            }
        }
        return min(a1[s1],a2[s2]);
    }
};
