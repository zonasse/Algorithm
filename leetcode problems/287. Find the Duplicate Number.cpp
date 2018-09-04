class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        while(true){
            slow = nums[slow];
            t = nums[t];
            if(slow == t) break;
        }
        return slow;
    }
};
class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1,right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            int cnt = 0;
            for(auto &a : nums){
                if(a <= mid) cnt++;
            }
            if(cnt <= mid) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
