class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n < 1 || primes.size() == 0) return -1;
        vector<int> res(1,1);
        vector<int> idx(primes.size(),0);
        while(res.size() < n){
            vector<int> temp;
            int mn = INT_MAX;
            for(int i=0; i<primes.size(); ++i){
                temp.push_back(res[idx[i]]*primes[i]);
            }
            for(int i=0; i<primes.size(); ++i){
                mn = min(mn,temp[i]);
            }
            for(int i=0; i<primes.size(); ++i){
                if(mn == temp[i]) idx[i]++;
            }
            res.push_back(mn);
        }
        return res.back();
    }
};
