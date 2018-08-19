class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int curR = 0;
        int curC = n-1;
        while(curR < m && curC >= 0){
            if(matrix[curR][curC] == target) return true;
            if(matrix[curR][curC] > target){
                curC--;
            }else{
                curR++;
            }
        }
        return false;

    }
};
