struct Edge{
    string name;
    double cost;
};
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, vector<Edge> > graph;
        map<string, bool> mark;
        for(int i=0; i<equations.size(); ++i){
            vector<Edge> temp;
            graph[equations[i].first] = temp;
            graph[equations[i].second] = temp;
            mark[equations[i].first] = false;
            mark[equations[i].second] = false;
        }
        for(int i=0; i<equations.size(); ++i){
            pair<string,string> one = equations[i];
            double cost = values[i];
            
            Edge edge;
            
            edge.name = one.second;
            edge.cost = cost;
            graph[one.first].push_back(edge);
            
            edge.name = one.first;
            edge.cost = 1/cost;
            graph[one.second].push_back(edge);
        }
        //search
        vector<double> res;
        for(int i=0; i<queries.size(); ++i){
            string start = queries[i].first;
            string end = queries[i].second;

            if(graph.find(start) == graph.end() || graph.find(end) == graph.end()){
                res.push_back(-1.0);
                continue;
            }
            if(start == end) {
                res.push_back(1.0);
                continue;
            }
            double ans = -1.0;
            mark[start] = true;
            
            dfs(start,end,graph,mark,1.0,ans);
            mark[start] = false;
            res.push_back(ans);
        }
        return res;
    }
    void dfs(string start, string end, map<string, vector<Edge> > &graph, map<string, bool> mark, double middle, double &ans){
        vector<Edge> temp = graph[start];
        for(int i=0; i<temp.size(); ++i){
            Edge edge = temp[i];
            if(mark[edge.name]) continue;
            mark[edge.name] = true;
            if(edge.name == end){
                ans = middle*edge.cost;
                return;
            }else{
                dfs(edge.name ,end ,graph ,mark ,middle*edge.cost ,ans);
                
            }
        }
    }
};