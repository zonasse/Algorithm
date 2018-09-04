class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return ;
        int m = board.size();
        int n = board[0].size();
        static const int dx[] = {-1,1,0,0,-1,-1,1,1};
        static const int dy[] = {0,0,-1,1,-1,1,-1,1};
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                int cnt = 0;
                for(int k=0; k<8; ++k){
                    int newX = i+dx[k];
                    int newY = j+dy[k];
                    if(newX >= 0 && newX < m && newY >= 0 && newY < n && (board[newX][newY] == 1 || board[newX][newY] == 2)) cnt++;
                }
                if(board[i][j] == 0 && cnt == 3) board[i][j] = 3;
                if(board[i][j] == 1 && (cnt > 3 || cnt < 2)) board[i][j] = 2;
            }
        }
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                board[i][j] %= 2;
            }
        }
    }
};
