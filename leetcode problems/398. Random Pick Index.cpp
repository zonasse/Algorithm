class Solution {
public:
    Solution(vector<int> nums):array(nums) {
        
    }
    
    int pick(int target) {
        int cnt = 0;
        int res = -1;
        for(int i=0; i<array.size(); ++i){
            if(target == array[i]){
                cnt++;
                if(rand() % cnt == 0) res = i;
            }
        }
        return res;
    }
private:
    vector<int> array;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */