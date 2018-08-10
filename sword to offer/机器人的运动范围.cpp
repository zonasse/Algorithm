/*
 * 机器人可回退
 */
const int maxn = 101;
class Solution {
public:
    int mark[maxn][maxn];
    int movingCount(int k, int rows, int cols)
    {
        if(rows <= 0 || cols <= 0 || k<=0){
            return 0;
        }
        //构建数组
        vector<vector<int> > mat;
        for(int i=0; i<rows; ++i){
            vector<int> temp;
            for(int j=0; j<cols; ++j){
                temp.push_back(cal(i)+cal(j));
            }
            mat.push_back(temp);
        }
        int ans = 0;
        memset(mark,false,sizeof(mark));
        search(mat,0,0,ans,k);
        return ans;
    }
    void search(vector<vector<int> > &mat,int x,int y,int &ans,int k){
        if(x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size() || mark[x][y] || mat[x][y] > k){
            return;
        }
        ans++;
        mark[x][y] = true;
        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,-1,1};
        for(int i=0; i<4; ++i){
            int newX = x+dx[i];
            int newY = y+dy[i];
            search(mat,newX,newY,ans,k);
        }
    }

    int cal(int x){
        int sum = 0;
        while(x){
            sum += x%10;
            x/=10;
        }
        return sum;
    }
};
/*
 * 机器人不可回退
 */
 const int maxn = 101;
class Solution {
public:
    int mark[maxn][maxn];
    int movingCount(int k, int rows, int cols)
    {
        if(rows <= 0 || cols <= 0 || k<=0){
            return 0;
        }
        //构建数组
        vector<vector<int> > mat;
        for(int i=0; i<rows; ++i){
            vector<int> temp;
            for(int j=0; j<cols; ++j){
                temp.push_back(cal(i)+cal(j));
            }
            mat.push_back(temp);
        }
        int ans = 1;
        memset(mark,false,sizeof(mark));
        search(mat,0,0,1,ans,k);
        return ans;
    }
    void search(vector<vector<int> > &mat,int x,int y,int cur,int &ans,int k){
        if(x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size() || mark[x][y] || mat[x][y] <= k){
            return;
        }
        if(cur > ans){
            ans = cur;
        }
        mark[x][y] = true;
        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,-1,1};
        for(int i=0; i<4; ++i){
            int newX = x+dx[i];
            int newY = y+dy[i];
            search(mat,newX,newY,cur+1,ans,k);
            mark[x][y] = false;
        }
    }

    int cal(int x){
        int sum = 0;
        while(x){
            sum += x%10;
            x/=10;
        }
        return sum;
    }
};
