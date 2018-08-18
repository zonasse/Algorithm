class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ret(n,vector<int> (n,0));
        int cur = 1;
        int minR = 0;
        int maxR = n-1;
        int minC = 0;
        int maxC = n-1;
        while(minR <= maxR && minC <= maxC){
            for(int i = minC; i<= maxC; ++i){
                ret[minR][i] = cur++;
            }
            minR++;
            for(int i=minR; i<=maxR; ++i){
                ret[i][maxC] = cur++;
            }
            maxC--;
            if(minR > maxR) break;
            for(int i=maxC; i>= minC; --i){
                ret[maxR][i] = cur++;
            }
            maxR--;
            if(minC > maxC) break;
            for(int i=maxR; i>= minR; --i){
                ret[i][minC] = cur++;
            }
            minC++;

        }
        return ret;
    }
};
