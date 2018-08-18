class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m <= 0 || n <= 0) return 0;
        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int> > mat(m+1,vector<int> (n+1,0));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                mat[i+1][j+1] = obstacleGrid[i][j] == 0? 0:INT_MAX;
            }
        }
        mat[1][1] = 1;
        if(mat[m][n] == INT_MAX) return 0;
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(i == 1 && j == 1) continue;
                if(mat[i][j] == INT_MAX) continue;
                mat[i][j] = (mat[i-1][j] == INT_MAX ? 0:mat[i-1][j]) + (mat[i][j-1] == INT_MAX ? 0:mat[i][j-1]);
            }
        }
        return mat[m][n];
    }
};
