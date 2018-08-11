class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty() || numRows <= 1){
            return s;
        }
        vector<string> matrix(numRows);
        int direct = 1;
        int row = 0;
        for(int i=0; i<s.size(); ++i){
            matrix[row] += s[i];
            row+=direct;
            if(row >= numRows){
                row = numRows-2;
                direct = -1;
            }
            if(row < 0){
                row = 1;
                direct = 1;
            }
        }
        string ret = "";
        for(int i=0; i<numRows; ++i){
            ret += matrix[i];
        }
        return ret;
    }
};
