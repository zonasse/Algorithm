#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
class Solution{
public:
    void flood_fill(vector<vector<int> > &graph,int x,int y,int oldColor,int newColor){
        if(x >= 0 && x <graph.size() && y>=0 && y<graph[0].size() && graph[x][y] != newColor){
            graph[x][y] = newColor;
            static int dx[] = {-1,1,0,0};
            static int dy[] = {0,0,1,-1};
            for(int i=0; i<4; ++i){
                int newX = x + dx[i];
                int newY = y + dy[i];
                flood_fill(graph,newX,newY,oldColor,newColor);
            }
        }

    }


};

int main(){
    vector<vector<int> > graph = {{0,1,0,1},{1,0,0,1},{0,0,1,0},{0,1,0,0}};
    Solution handle;
    handle.flood_fill(graph,2,1,0,1);
    for(int i=0; i<graph.size(); ++i){
        for(int j=0; j<graph[0].size(); ++j){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}
