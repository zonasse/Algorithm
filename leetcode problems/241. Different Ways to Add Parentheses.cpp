class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i=0; i<input.size(); ++i){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> leftResult = diffWaysToCompute(input.substr(0,i));
                vector<int> rightResult = diffWaysToCompute(input.substr(i+1,input.size()-i-1));
                for(int j=0; j<leftResult.size(); ++j){
                    for(int k=0; k<rightResult.size(); ++k){
                        if(input[i] == '+'){
                            res.push_back(leftResult[j]+rightResult[k]);
                        }else if(input[i] == '-'){
                            res.push_back(leftResult[j]-rightResult[k]);
                        }if(input[i] == '*'){
                            res.push_back(leftResult[j]*rightResult[k]);
                        }
                    }
                }
            }
        }
        if(res.empty()) res.push_back(atoi(input.c_str()));
        return res;
    }
};
