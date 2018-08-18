class Solution {
public:
    int minPathSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        if(m <= 0 || n <= 0) return 0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i == 0 && j==0) continue;
                if(i == 0){
                    mat[i][j] += mat[i][j-1];
                }else if(j == 0){
                    mat[i][j] += mat[i-1][j];
                }else{
                    mat[i][j] += min(mat[i-1][j],mat[i][j-1]);
                }

            }
        }
        return mat[m-1][n-1];
    }
};
