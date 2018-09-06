class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        dp = matrix;
        for(int i=1; i<dp.size(); ++i){
            dp[i][0] += dp[i-1][0];
        }
        for(int j=1; j<dp[0].size(); ++j){
            dp[0][j] += dp[0][j-1];
        }
        for(int i=1; i<dp.size(); ++i){
            for(int j=1; j<dp[0].size(); ++j){
                dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(dp.size() == 0 || dp[0].size() == 0) return -1;
        if(row1 == 0 && col1 == 0) return dp[row2][col2];
        if(row1 == 0) return dp[row2][col2] - dp[row2][col1-1];
        if(col1 == 0) return dp[row2][col2] - dp[row1-1][col2];
        return dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1] + dp[row1-1][col1-1];
    }
private:
    vector<vector<int> > dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
