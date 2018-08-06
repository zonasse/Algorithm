#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
const int INF = 0x7fffffff;
struct edge{
    int weight;
    int to;
};
vector<edge> graph[maxn];
bool mark[maxn];
int dis[maxn];
int vexNum,arcNum;
void initGraph(){
    printf("请输入节点数和边数：");
    scanf("%d%d",&vexNum,&arcNum);
    for(int i=0; i<=vexNum; ++i){
        graph[i].clear();
    }
    for(int i=1; i<=arcNum; ++i){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edge temp;
        temp.weight = w;
        temp.to = a;
        graph[b].push_back(temp);
        temp.to = b;
        graph[a].push_back(temp);
    }
    memset(mark,false,sizeof(mark));
    memset(dis,-1,sizeof(dis));
}
void dijkstra(vector<edge> graph[],int src){
    dis[src] = 0;
    mark[src] = true;
    int newP = src;
    for(int i=1; i<vexNum; ++i){

        for(int j=0; j<graph[newP].size(); ++j){
            int to = graph[newP][j].to;
            int w = graph[newP][j].weight;
            if(mark[to] == true)continue;
            if(dis[to] == -1 || dis[to] > w + dis[newP]){
                dis[to] = w+dis[newP];
            }
        }
        int _min = INF;
        for(int j=1; j<=vexNum; ++j){
            if(mark[j] == true)continue;
            if(dis[j] == -1)continue;
            if(dis[j] < _min){
                _min = dis[j];
                newP = j;
            }
        }
        mark[newP] = true;
    }

}

int main(){
    initGraph();
    dijkstra(graph,2);
    for(int i=1; i<=vexNum; ++i){
        printf("%d ",dis[i]);
    }
    return 0;
}
