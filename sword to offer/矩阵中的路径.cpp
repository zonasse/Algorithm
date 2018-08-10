const int maxn = 101;
class Solution {
public:
    bool mark[maxn][maxn];
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(!matrix || !str){
            return false;
        }
        vector<vector<char> > mat;
        for(int i=0; i<rows; ++i){
            vector<char> temp;
            for(int j=0; j<cols; ++j){
                temp.push_back(matrix[i*cols+j]);
            }
            mat.push_back(temp);
        }
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(mat[i][j] == *str){
                    bool search = false;
                    memset(mark,false,sizeof(mark));
                    find(mat,i,j,str,search);
                    if(search){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void find(vector<vector<char> > &mat,int x,int y,char *str,bool &search){
        if(*str == '\0'){
            search = true;
            return;
        }
        if(search || x < 0 || x >= (int)mat.size() || y < 0 || y >= (int)mat[0].size() || mark[x][y] || mat[x][y] != *str){
            return;
        }

        mark[x][y] = true;
        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,-1,1};
        for(int i=0; i<4; ++i){
            int newX = x+dx[i];
            int newY = y+dy[i];
            find(mat,newX,newY,str+1,search);
        }
    }

};
