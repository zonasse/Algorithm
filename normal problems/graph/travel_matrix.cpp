#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
const int INF = 0x7fffffff;
struct Graph{
    int vexs[maxn];
    int arcs[maxn][maxn];
    int vexNum;
    int arcNum;
};
bool visited[maxn];
void initGraph(Graph *G);
void DFS(Graph *G);
void dfs(Graph *G,int i);
void BFS(Graph *G,int start);


void initGraph(Graph *G){
    printf("输入顶点数和边数：");
    scanf("%d%d",&G->vexNum,&G->arcNum);
    //建立节点
    printf("输入节点编号：");
    for(int i=0; i<G->vexNum; ++i){
        scanf("%d",&G->vexs[i]);
    }
    //初始化边
    memset(G->arcs,INF,sizeof(G->arcs));
    //建立边
    printf("输入边的左右两个节点的编号及边的权重:\n");
    for(int i=0; i<G->arcNum; ++i){
        int from,to,weight;
        scanf("%d%d%d",&from,&to,&weight);
        G->arcs[from][to] = weight;
        G->arcs[to][from] = G->arcs[from][to];
    }
}

void DFS(Graph *G){
    memset(visited,false,sizeof(visited));
    for(int i=0; i<G->vexNum; ++i){
        if(visited[i] == false){
            dfs(G,i);
        }
    }

}
void dfs(Graph *G,int i){
    visited[i] = true;
    printf("%d ",G->vexs[i]);
    for(int j=0; j<G->vexNum; ++j){
        if(G->arcs[i][j] != 0 && G->arcs[i][j] != INF && visited[j] == false){
            dfs(G,j);
        }
    }
}
void BFS(Graph *G,int start){
    memset(visited,false,sizeof(visited));
    queue<int> Q;
    visited[start] = true;
    Q.push(start);
    while(Q.empty() == false){
        int cur = Q.front();
        printf("%d ",cur);
        Q.pop();
        for(int i=0; i<G->vexNum; ++i){
            if(G->arcs[cur][i] != INF && G->arcs[cur][i] != 0 && visited[i] == false){
                visited[i] = true;
                Q.push(i);
            }
        }
    }

}

int main(){
    Graph *G = new Graph();
    initGraph(G);
    BFS(G,0);
    return 0;
}
