#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
/*
 *  邻接表两种表示方法
 */
//方法1：边有属性
struct edge{
    int weight;
    int to;
};
vector<edge> graph1[maxn];
//方法2：节点有属性
struct vex{
    int data;
    vector<vex> edges;
};
vex graph2[maxn];

//采用方法1表示的邻接表实现DFS
class Solution{
public:
    void DFS(vector<edge> graph[],int startVex){
        memset(_mark,false,sizeof(_mark));
        _dfs(graph,startVex);
    }


private:
    bool _mark[maxn];
    void _dfs(vector<edge> graph[],int startVex){
        printf("%d ",startVex);
        _mark[startVex] = true;
        for(int i=0; i<graph[startVex].size(); ++i){
            int dest = graph[startVex][i].to;
            if(_mark[dest] == false){
                _dfs(graph,dest);
            }
        }
    }
};

int main(){
    for(int i=0; i<5; ++i){
        int v;
        edge f;
        scanf("%d%d%d",&v,&f.to,&f.weight);
        graph1[v].push_back(f);
    }
    Solution handle;
    handle.DFS(graph1,1);
    return 0;
}
