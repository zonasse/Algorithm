/*
 * O(n^2)暴力解法，超时
 */
class Solution1 {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.size() == 0) return 0;
        int res = INT_MIN;
        int n = A.size();
        for(int k=0; k<n; ++k){
            int fk = 0;
            for(int i=0; i<n; ++i){
                fk += (k+i+ n)%n * A[i];  
            }
            res = max(res,fk);
        }
        return res;
    }
};
/*
 * O(n) AC
 */
class Solution2 {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.size() == 0) return 0;
        int sum = 0;
        int t = 0;
        int n = A.size();
        for(int i=0; i<n; ++i){
            sum += A[i];
            t += i*A[i];
        }
        int res = t;
        for(int i=1; i<n; ++i){
            t = t + sum - n*A[n-i];
            res = max(res,t);
        }
        return res;
    }
};