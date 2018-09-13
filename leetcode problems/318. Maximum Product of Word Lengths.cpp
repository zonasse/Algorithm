class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> hash(words.size(),0);
        int res = 0;
        for(int i=0; i<words.size(); ++i){
            for(char ch : words[i]){
                hash[i] |= 1 << (ch - 'a');
            }
            for(int j=0; j<i; ++j){
                if((hash[i] & hash[j]) == 0){
                    res = max(res,(int)(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};
