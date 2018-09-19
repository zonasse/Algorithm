struct cmp{
    bool operator()(pair<int,int> &p1,pair<int,int> &p2){
        int num1 = p1.first + p1.second;
        int num2 = p2.first + p2.second;
        return num1 < num2;
    }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int size = 0;
        priority_queue<pair<int,int> ,vector<pair<int,int> >, cmp> Q;
        for(int l1 = 0; l1 < min(k,(int)nums1.size()); ++l1){
            for(int l2 = 0; l2 < min(k,(int)nums2.size()); ++l2){
                pair<int,int> cur = make_pair(nums1[l1],nums2[l2]);
                if(size != k){
                    Q.push(cur);
                    size++;
                }else{
                    if(less(cur,Q.top())){
                        Q.pop();
                        Q.push(cur);
                    }
                }
            }
        }
        vector<pair<int,int> > res;
        while(Q.empty() == false){
            res.push_back(Q.top());
            Q.pop();
        }
        return res;
    }
    bool less(const pair<int,int> &p1,const pair<int,int> &p2){
        int num1 = p1.first + p1.second;
        int num2 = p2.first + p2.second;
        return num1 < num2;
    }
};
