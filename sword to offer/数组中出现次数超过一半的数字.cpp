class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() < 1){
            return 0;
        }
        int result = numbers[0];
        int times = 1;
        for(int i=1; i<numbers.size(); ++i){
            if(times == 0){
                result = numbers[i];
                times = 1;
            }else if(numbers[i] == result){
                times++;
            }else{
                times--;
            }
        }
        if(check(numbers,result)){
            return result;
        }else{
            return 0;
        }
    }
    bool check(vector<int> numbers,int target){
        int times = 0;
        for(int i=0; i<numbers.size(); ++i){
            if(numbers[i] == target){
                times++;
            }else{
                times--;
            }
        }
        if(times > 0){
            return true;
        }else{
            return false;
        }
    }
};
