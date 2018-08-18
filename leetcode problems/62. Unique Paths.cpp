class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0) return 0;
        vector<vector<int> > mat(m+1,vector<int> (n+1,0));
        mat[1][1] = 1;
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(i == 1 && j == 1) continue;
                mat[i][j] = mat[i-1][j] + mat[i][j-1];
            }
        }
        return mat[m][n];
    }
};
