class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            while(!Q.empty() && nums[Q.back()] <= nums[i]){
                Q.pop_back();
            }
            Q.push_back(i);
            //队头过期
            if(Q.front() + k == i){
                Q.pop_front();
            }
            //从k-1位置开始给出窗口最大值
            if(i >= k - 1){
                res.push_back(nums[Q.front()]);
            }
        }
        return res;
    }
};
