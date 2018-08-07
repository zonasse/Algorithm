class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int> Q;//建立大根堆
        vector<int> ret;
        if(k < 1 || input.size() < k){
            return ret;
        }
        for(int i=0; i<input.size(); ++i){
            if(Q.size() < k){
                Q.push(input[i]);
            }else{
                if(input[i] < Q.top()){
                    Q.pop();
                    Q.push(input[i]);
                }
            }
        }
        while(Q.empty() == false){
            ret.insert(ret.begin(),Q.top());
            Q.pop();
        }
        return ret;
    }
};
