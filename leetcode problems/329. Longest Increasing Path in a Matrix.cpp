class Solution1 {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > mark(row,vector<int> (col,0));
        int res = 0;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                res = max(res,dfs(matrix,i,j,mark));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix,int x,int y,vector<vector<int> > &mark){
        if(mark[x][y]) return mark[x][y];
        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,1,-1};
        int mx = 1;
        for(int i=0; i<4; ++i){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(legal(newX,newY,matrix.size(),matrix[0].size()) && matrix[newX][newY] > matrix[x][y]){
                int len = 1 + dfs(matrix,newX,newY,mark);
                mx = max(mx,len);
            }
        }
        mark[x][y] = mx;
        return mx;
    }
    bool legal(int x,int y,int row,int col){
        return x >= 0 && x < row && y >= 0 && y < col;
    }
};
/*
 * ³¬Ê±
 */
 class Solution2 {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<bool> > mark(row,vector<bool> (col,false));
        int res = 0;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                dfs(matrix,i,j,0,res,mark);
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& matrix,int x,int y,int count,int &res,vector<vector<bool> > mark){
        count++;
        if(count > res) res = count;
        mark[x][y] = true;
        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,1,-1};
        for(int i=0; i<4; ++i){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(legal(newX,newY,matrix.size(),matrix[0].size()) && mark[newX][newY] == false && matrix[newX][newY] > matrix[x][y]){
                dfs(matrix,newX,newY,count,res,mark);
            }
        }
    }
    bool legal(int x,int y,int row,int col){
        return x >= 0 && x < row && y >= 0 && y < col;
    }
};
