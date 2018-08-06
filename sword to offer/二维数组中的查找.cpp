class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()){
            return false;
        }
        int row = array.size();
        int col = array[0].size();
        int curRow = 0;
        int curCol = col-1;
        while(curRow < row && curCol >= 0){
            int curNum = array[curRow][curCol];
            if(curNum > target){
                curCol--;
            }else if(curNum < target){
                curRow++;
            }else{
                return true;
            }
        }
        return false;
    }
};
