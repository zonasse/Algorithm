class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty()){
            return false;
        }
        stack<int> support;
        int popIndex = 0;
        for(int i=0; i<pushV.size(); ++i){
            support.push(pushV[i]);
            while(support.empty() == false && support.top() == popV[popIndex]){
                support.pop();
                popIndex++;
            }
        }
        return support.empty();
    }
};
