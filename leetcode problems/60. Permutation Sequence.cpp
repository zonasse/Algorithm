class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string nums = "123456789";
        k--;
        vector<int> f(n+1,1);
        for(int i=1; i<=n; ++i){
            f[i] = f[i-1]*i;
        }
        for(int i=n; i>=1; --i){
            int groupNum = k/f[i-1];
            k %= f[i-1];
            res.push_back(nums[groupNum]);
            nums.erase(groupNum,1);
        }
        return res;
    }
};
