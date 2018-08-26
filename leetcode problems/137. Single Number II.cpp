class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<32; ++i){
            int times = 0;
            for(int j=0; j<nums.size(); ++j){
                if(nums[j] >> i  & 1){
                    times++;
                }
            }
            if(times % 3){
                res |= 1 << i;
            }
        }
        return res;
    }
};
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int k = 3;
        vector<int> bits(32,0);
        for(int i=0; i<nums.size(); ++i){
            vector<int> kNum = changeNumToKBit(nums[i],k);
            for(int j=0; j<bits.size(); ++j){
                bits[j] = (bits[j] + kNum[j]) % k;

            }
        }
        int res = 0;
        for(int i=bits.size()-1; i>=0; --i){
            res = res*k + bits[i];
        }
        return res;
    }
    vector<int> changeNumToKBit(int num,int k){
        vector<int> kNum(32,0);
        int index = 0;
        while(num){
            kNum[index++] = num%k;
            num/=k;
        }
        return kNum;
    }
};
