class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ret;
        if(sum < 3){
            return ret;
        }
        int small = 1;
        int big = 2;
        int curSum = 3;
        while(small < (sum+1)/2 && big < sum){
            if(curSum > sum){
                curSum-=small;
                small++;
            }else if(curSum < sum){
                big++;
                curSum+=big;
            }else{
                vector<int> temp;
                for(int i=small ; i<=big; ++i){
                    temp.push_back(i);
                }
                ret.push_back(temp);
                big++;
                curSum+=big;
            }
        }
        return ret;
    }
};
