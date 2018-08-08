class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int target) {
        vector<int> ret;
        if(array.empty()){
            return ret;
        }
        int num1;
        int num2;

        int pre = 0;
        int after = array.size()-1;
        while(pre < after){
            int sum = array[pre] + array[after];
            if(sum == target){
                num1 = array[pre];
                num2 = array[after];
                if(ret.empty()){
                    ret.push_back(num1);
                    ret.push_back(num2);
                }else if(num1*num2 < ret[0]*ret[1]){
                    ret[0] = num1;
                    ret[1] = num2;
                }
                pre++;
                after--;
            }else if(sum > target){
                after--;
            }else{
                pre++;
            }
        }
        return ret;
    }
};
