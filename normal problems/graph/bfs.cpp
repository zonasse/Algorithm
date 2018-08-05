#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
struct edge{
    int weight;
    int to;
};

vector<edge> graph[maxn];

class Solution{
public:
    void BFS(vector<edge> graph[],int startVex){
        memset(mark,false,sizeof(mark));
        queue<int> Q;
        Q.push(startVex);
        mark[startVex] = true;
        while(Q.empty() == false){
            int cur = Q.front();
            printf("%d ",cur);
            Q.pop();
            for(int i=0; i<graph[cur].size(); ++i){
                int dest = graph[cur][i].to;
                if(mark[dest] == false){
                    Q.push(dest);
                    mark[dest] = true;
                }
            }
        }

    }
private:
    bool mark[maxn];


};

int main(){
    for(int i=0; i<5; ++i){
        int v;
        edge f;
        scanf("%d%d%d",&v,&f.to,&f.weight);
        graph[v].push_back(f);
    }
    Solution handle;
    handle.BFS(graph,1);
    return 0;
}
