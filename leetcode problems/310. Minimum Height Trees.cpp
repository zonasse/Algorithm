class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        vector<int> res;
        vector<unordered_set<int> > Graph(n);
        for(int i=0; i<edges.size(); ++i){
            int first = edges[i].first;
            int second = edges[i].second;
            Graph[first].insert(second);
            Graph[second].insert(first);
        }
        queue<int> Q;
        for(int i=0; i<n; ++i){
            if(Graph[i].size() == 1){
                Q.push(i);
            }
        }
        int size = n;
        while(size > 2){
            size -= Q.size();
            int curSize = Q.size();
            for(int i=0; i<curSize; ++i){
                int next = Q.front();
                Q.pop();
                for(auto a : Graph[next]){
                    Graph[a].erase(next);
                    if(Graph[a].size() == 1){
                        Q.push(a);
                    }
                }
            }
        }
        while(Q.empty() == false){
            res.push_back(Q.front());
            Q.pop();
        }
        return res;
    }
};
/*
 * 超时代码
 */
struct Node{
    vector<int> neighbors;
};
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_map<int,vector<int> > M;
        vector<Node*> Graph(n);
        for(int i=0; i<n; ++i){
            Graph[i] = new Node();
        }
        int minLevel = INT_MAX;
        /*
         * 构建图
         */
        for(int i=0; i<edges.size(); ++i){
            int first = edges[i].first;
            int second = edges[i].second;
            Graph[first]->neighbors.push_back(second);
            Graph[second]->neighbors.push_back(first);
        }
        bool mark[n];
        for(int i=0; i<n; ++i){
            /*
             * 找出以每个节点为根节点的最大深度
             */
            memset(mark,false,sizeof(mark));
            queue<int> Q;
            Q.push(i);
            int level = 0;
            int last = i;
            int nlast = -1;
            while(Q.empty() == false){
                int t = Q.front();
                mark[t] = true;
                Q.pop();
                for(int j=0; j<Graph[t]->neighbors.size(); ++j){
                    int next = Graph[t]->neighbors[j];
                    if(mark[next]) continue;
                    nlast = next;
                    Q.push(next);
                }
                if(t == last){
                    last = nlast;
                    level++;
                }
            }
            minLevel = min(minLevel,level);
            M[level].push_back(i);
        }
        return M[minLevel];
    }
};
