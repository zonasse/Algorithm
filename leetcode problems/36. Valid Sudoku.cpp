class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() < 9) return false;
        set<char> char_set;
        for(int i=0; i<3; ++i){
            //检查行
            for(int r=i*3; r<3*i+3; ++r){
                char_set.clear();
                for(int k=0; k<9; ++k){
                    if(board[r][k] == '.') continue;
                    if(char_set.find(board[r][k]) == char_set.end()){
                        char_set.insert(board[r][k]);
                    }else{
                        return false;
                    }
                }
            }
            for(int j=0; j<3; ++j){
                //检查列
                for(int c=j*3; c<3*j+3; ++c){
                    char_set.clear();
                    for(int k=0; k<9; ++k){
                        if(board[k][c] == '.') continue;
                        if(char_set.find(board[k][c]) == char_set.end()){
                            char_set.insert(board[k][c]);
                        }else{
                            return false;
                        }
                    }
                }
                //检查以(i,j)为左上角的九宫格
                char_set.clear();
                for(int r=i*3; r<i*3+3; ++r){
                    for(int c=j*3; c<j*3+3; ++c){
                        if(board[r][c] == '.') continue;
                        if(char_set.find(board[r][c]) == char_set.end()){
                            char_set.insert(board[r][c]);
                        }else{
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
class Solution2 {
public:
    bool check(char ch,bool used[9]){
        if(ch == '.'){
            return true;
        }
        if(used[ch-'1']){
            return false;
        }
        used[ch-'1'] = true;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];
        //检查行列
        for(int i=0; i<9; ++i){
            memset(used,false,sizeof(used));
            for(int j=0; j<9; ++j){
                if(!check(board[i][j],used)){
                    return false;
                }
            }
            memset(used,false,sizeof(used));
            for(int j=0; j<9; ++j){
                if(!check(board[j][i],used)){
                    return false;
                }
            }
        }
        //检查9个子格
        for(int row=0; row<3; ++row){
            for(int col=0; col<3; ++col){
                memset(used,false,sizeof(used));
                for(int i=row*3; i<row*3+3; ++i){
                    for(int j=col*3; j<col*3+3; ++j){
                        if(!check(board[i][j],used)){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

};
