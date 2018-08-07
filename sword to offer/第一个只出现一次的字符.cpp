class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> M;
        for(int i=0; i<str.size(); ++i){
            M[str[i]]++;
        }
        for(int i=0; i<str.size(); ++i){
            if(M[str[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
