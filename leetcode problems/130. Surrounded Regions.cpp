class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool> > mark(m+1,vector<bool> (n+1,false));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(mark[i][j] == false && board[i][j] == 'O' && (i == 0 || i == m-1 || j == 0 || j == n-1)){
                    dfs(board,i,j,mark);
                }
            }
        }
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == 'O' && mark[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board,int r,int c,vector<vector<bool> > &mark){
        if(r >= board.size() || r < 0 || c >= board[0].size() || c < 0
          || board[r][c] == 'X' || mark[r][c]) return;
        mark[r][c] = true;
        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,-1,1};
        for(int i=0; i<4; ++i){
            int newX = r + dx[i];
            int newY = c + dy[i];
            dfs(board,newX,newY,mark);
        }
    }
};
