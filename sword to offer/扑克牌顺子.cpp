class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() < 5){
            return false;
        }
        int zeroNum = 0;
        int gapNum = 0;
        sort(numbers.begin(),numbers.end());
        for(int i=0; i<numbers.size(); ++i){
            if(numbers[i] == 0){
                zeroNum++;
            }
        }
        int small = zeroNum;
        int big = small+1;
        while(big < numbers.size()){
            if(numbers[small] == numbers[big]){
                return false;
            }
            gapNum += numbers[big] - numbers[small] - 1;
            small = big;
            big++;
        }
        return gapNum > zeroNum ? false:true;
    }
};
