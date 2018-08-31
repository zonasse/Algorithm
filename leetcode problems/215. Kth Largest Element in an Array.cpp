class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() < k) return -1;
        priority_queue<int,vector<int>,greater<int> > Q;
        for(int i=0; i<nums.size(); ++i){
            if(Q.size() < k){
                Q.push(nums[i]);
            }else{
                if(Q.top() < nums[i]){
                    Q.pop();
                    Q.push(nums[i]);
                }
            }
        }
        return Q.top();
    }
};
