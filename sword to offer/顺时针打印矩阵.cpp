class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        if(matrix.empty()){
            return ret;
        }
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        while(left <= right && top <= bottom){
            //ср
            if(left > right) break;
            for(int i=left; i<=right; ++i){
                ret.push_back(matrix[top][i]);
            }
            top++;
            //об
            if(top > bottom) break;
            for(int i=top; i<=bottom; ++i){
                ret.push_back(matrix[i][right]);
            }
            right--;
            //вС
            if(left > right) break;
            for(int i=right; i>=left; --i){
                ret.push_back(matrix[bottom][i]);
            }
            bottom--;
            //ио
            if(top > bottom) break;
            for(int i=bottom; i>=top; --i){
                ret.push_back(matrix[i][left]);
            }
            left++;
        }

        return ret;
    }
};
