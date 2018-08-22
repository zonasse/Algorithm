class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() < 1) return 0;
        for(int i=1; i<triangle.size(); ++i){
            for(int j=0; j<=i; ++j){
                if(j == 0){
                    triangle[i][0] += triangle[i-1][0];
                }else if(j == i){
                    triangle[i][j] += triangle[i-1][j-1];
                }else{
                    triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
                }
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<triangle.size(); ++j){
            ans = min(ans,triangle[triangle.size()-1][j]);
        }
        return ans;
    }
};
