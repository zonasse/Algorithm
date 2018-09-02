class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        if(target < matrix[0][0] || target > matrix.back().back()) return false;
        int curR = 0;
        int curC = matrix[0].size()-1;
        while(curR < matrix.size() && curC >= 0){
            if(matrix[curR][curC] == target){
                return true;
            }else if(matrix[curR][curC] > target){
                curC--;
            }else{
                curR++;
            }
        }
        return false;
    }
};
