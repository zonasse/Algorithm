#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
const int INF = -1;
int vexNum,arcNum;
int matrix[maxn][maxn];
void floyd(){
    for(int k = 1; k<=vexNum; ++k){
        for(int i=1; i<=vexNum; ++i){
            for(int j=1; j<=vexNum; ++j){
                if(matrix[i][k] == INF || matrix[k][j] == INF) continue;
                if(matrix[i][j] == INF || matrix[i][k] + matrix[k][j] < matrix[i][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

}
int main(){
    memset(matrix,INF,sizeof(matrix));
     printf("请输入节点数和边数：");
    scanf("%d%d",&vexNum,&arcNum);

    for(int i=1; i<=arcNum; ++i){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        matrix[a][b] = matrix[b][a] = w;
        matrix[a][a] = matrix[b][b] = 0;
    }
    floyd();
    for(int i=1; i<=vexNum; ++i){
        for(int j=1; j<=vexNum; ++j){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
