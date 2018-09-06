class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        /*
         * 将字符串拆成3个部分，num[0]->num[i],num[i+1]->num[j],num[j+1]->num[end]
         *
         */
        for(int i=0; i<=(len-1)/2-1; ++i){
            if(num[0] == '0' && i >= 1) break;
            for(int j=i+1; j<=len-i-2 && j-i <= len-1-j-1+1; ++j){
                if(num[i+1] == '0' && j-i > 1) break;
                long long num1 = stoll(num.substr(0,i+1));
                long long num2 = stoll(num.substr(i+1,j-i));
                if(isAdditive(num.substr(j+1),num1,num2)){
                    return true;
                }
            }
        }
        return false;
    }
    bool isAdditive(string remain,long long num1,long long num2){
        if(remain == "") return true;
        long long sum = num1 + num2;
        string sumstr = to_string(sum);
        if(remain.size() < sumstr.size() || remain.substr(0,sumstr.size()) != sumstr) return false;
        return isAdditive(remain.substr(sumstr.size()),num2,sum);
    }
};
