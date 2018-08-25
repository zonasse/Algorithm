class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > res;
        unordered_set<string> dict(wordList.begin(),wordList.end());

        vector<string> p{beginWord};
        queue<vector<string> > pathQ;
        pathQ.push(p);

        int curLevel = 1;
        int minLevel = INT_MAX;
        unordered_set<string> word_set;
        while(!pathQ.empty()){
            auto curPath = pathQ.front();
            pathQ.pop();
            if(curPath.size() > curLevel){
                for(string w : word_set) dict.erase(w);
                word_set.clear();
                curLevel = curPath.size();
                if(curLevel > minLevel) break;
            }
            string last = curPath.back();
            for(int i=0; i<last.size(); ++i){
                string newLast = last;
                for(char ch = 'a'; ch <= 'z'; ++ch){
                    newLast[i] = ch;
                    if(!dict.count(newLast)) continue;
                    word_set.insert(newLast);
                    vector<string> nextPath = curPath;
                    nextPath.push_back(newLast);
                    if(newLast == endWord){
                        res.push_back(nextPath);
                        minLevel = curLevel;
                    }else{
                        pathQ.push(nextPath);
                    }
                }
            }
        }
        return res;

    }
};
