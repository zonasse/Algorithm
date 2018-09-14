class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        map<string,multiset<string> > M;
        for(int i=0; i<tickets.size(); ++i){
            M[tickets[i].first].insert(tickets[i].second);
        }
        dfs(M,"JFK",res);
        return vector<string> (res.rbegin(),res.rend());
    }
    void dfs(map<string,multiset<string> > &M,string start,vector<string> &res){
        while(M[start].size()){
            string t = *M[start].begin();
            M[start].erase(M[start].begin());
            dfs(M,t,res);
        }
        res.push_back(start);
    }
};
