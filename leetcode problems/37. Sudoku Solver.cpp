class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty() || board.size() != 9 || board[0].size() != 9) return;
        boardDFS(board,0,0);
    }
    bool boardDFS(vector<vector<char>>& board,int r,int c){
        if(r == 9) return true;
        if(c >= 9) return boardDFS(board,r+1,0);
        if(board[r][c] == '.'){
            for(int k=1; k<=9; ++k){
                board[r][c] = (char)(k+'0');
                if(valid(board,r,c)){
                    if(boardDFS(board,r,c+1)){
                        return true;
                    }
                }
                board[r][c] = '.';
            }
        }else{
            return boardDFS(board,r,c+1);
        }
        return false;
    }
    bool valid(vector<vector<char>>& board,int r,int c){
        for(int col=0; col<9; ++col){
            if(col != c && board[r][col] == board[r][c]) return false;
        }
        for(int row=0; row<9; ++row){
            if(row != r && board[row][c] == board[r][c]) return false;
        }
        for(int row = (r/3)*3; row < (r/3*3)+3; ++row){
            for(int col = (c/3)*3; col < (c/3*3)+3; ++col){
                if((row != r || col != c) && board[row][col] == board[r][c]){
                    return false;
                }
            }
        }
        return true;
    }
};
