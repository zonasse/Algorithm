class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int> > height,res;
        multiset<int> m_set;
        int pre = 0,cur = 0;
        for(auto &a : buildings){
            height.push_back(make_pair(a[0],-a[2]));
            height.push_back(make_pair(a[1],a[2]));
        }
        sort(height.begin(),height.end());
        m_set.insert(0);
        for(auto &a : height){
            if(a.second < 0){
                m_set.insert(-a.second);
            }else{
                m_set.erase(m_set.find(a.second));
            }
            cur = *m_set.rbegin();
            if(cur != pre){
                res.push_back(make_pair(a.first,cur));
                pre = cur;
            }
        }
        return res;
    }
};
