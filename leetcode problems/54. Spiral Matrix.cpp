class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty()) return ret;
        int startR = 0;
        int startC = 0;
        int endR = matrix.size()-1;
        int endC = matrix[0].size()-1;
        while(startR <= endR && startC <= endC){
            for(int i=startC; i<=endC; ++i){
                ret.push_back(matrix[startR][i]);
            }
            startR++;
            for(int i=startR; i<=endR; ++i){
                ret.push_back(matrix[i][endC]);
            }
            endC--;
            if(startR > endR) break;
            for(int i=endC; i>=startC; --i){
                ret.push_back(matrix[endR][i]);
            }
            endR--;
            if(startC > endC) break;
            for(int i=endR; i>=startR; --i){
                ret.push_back(matrix[i][startC]);
            }
            startC++;

        }
        return ret;
    }
};
