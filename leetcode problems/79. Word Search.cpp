class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(word.empty()) return true;
        if(m == 0 || n == 0) return false;
        vector<vector<bool> > mark(board.size(),vector<bool> (board[0].size(),false));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,0,board,word,mark)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(int x,int y,int idx,vector<vector<char>>& board,string word,vector<vector<bool> > &mark){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
        if(board[x][y] != word[idx] || mark[x][y]) return false;
        if(idx == word.size()-1){
            return true;
        }
        mark[x][y] = true;
        bool ret = false;
        ret = dfs(x+1,y,idx+1,board,word,mark) ||
              dfs(x-1,y,idx+1,board,word,mark) ||
              dfs(x,y+1,idx+1,board,word,mark) ||
              dfs(x,y-1,idx+1,board,word,mark);
        mark[x][y] = false;
        return ret;
    }
};
