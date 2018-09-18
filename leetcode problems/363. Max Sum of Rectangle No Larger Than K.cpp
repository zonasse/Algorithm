/*
 * 列比行大得多
 */
 class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0 ) return 0;
        int res = INT_MIN;
        int row = matrix.size();
        int col = matrix[0].size();
        int sum[col];
        for(int i=0; i<row; ++i){
            memset(sum,0,sizeof(sum));
            for(int j=i; j<row; ++j){
                for(int k=0; k<col; ++k){
                    sum[k] += matrix[j][k];
                }
                int curSum = 0,curMax = INT_MIN;
                set<int> s;
                s.insert(0);
                for(int num : sum){
                    curSum += num;
                    auto it = s.lower_bound(curSum-target);
                    if(it != s.end()){
                        curMax = max(curMax,curSum-*it);
                    }
                    s.insert(curSum);
                }
                res = max(res,curMax);
            }

        }
        return res;
    }
};
/*
 * 行比列大得多
 */
 class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0 ) return 0;
        int res = INT_MIN;
        int row = matrix.size();
        int col = matrix[0].size();
        int sum[row];
        for(int i=0; i<col; ++i){
            memset(sum,0,sizeof(sum));
            for(int j=i; j<col; ++j){
                for(int k=0; k<row; ++k){
                    sum[k] += matrix[k][j];
                }
                int curSum = 0,curMax = INT_MIN;
                set<int> s;
                s.insert(0);
                for(int num : sum){
                    curSum += num;
                    auto it = s.lower_bound(curSum-target);
                    if(it != s.end()){
                        curMax = max(curMax,curSum-*it);
                    }
                    s.insert(curSum);
                }
                res = max(res,curMax);
            }

        }
        return res;
    }
};
