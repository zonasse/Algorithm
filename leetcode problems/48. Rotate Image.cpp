class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() < 2) return;
        int tR = 0;
        int tC = 0;
        int dR = matrix.size()-1;
        int dC = matrix[0].size()-1;
        while(tR < dR){
            rotateEdge(matrix,tR++,tC++,dR--,dC--);
        }
    }
    void rotateEdge(vector<vector<int> >& matrix,int tR,int tC,int dR,int dC){
        int times = dR-tR;
        int temp = 0;
        for(int i=0; i<times; ++i){
            temp = matrix[tR][tC+i];
            matrix[tR][tC+i] = matrix[dR-i][tC];
            matrix[dR-i][tC] = matrix[dR][dC-i];
            matrix[dR][dC-i] = matrix[tR+i][dC];
            matrix[tR+i][dC] = temp;
        }
    }
};
