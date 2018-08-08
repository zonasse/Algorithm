class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> ret;
        if(A.size() < 2){
            return ret;
        }
        ret.push_back(1);
        for(int i=0; i<A.size()-1; ++i){
            ret.push_back(ret.back()*A[i]);
        }
        int temp = 1;
        for(int i=A.size()-1; i>=0; --i){
            ret[i] = ret[i] * temp;
            temp*=A[i];
        }
        return ret;
    }
};
