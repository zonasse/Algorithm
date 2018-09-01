class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C-A)*(D-B) + (G-E)*(H-F);
        int x1 = max(A,E);
        int y1 = max(B,F);
        int x2 = min(C,G);
        int y2 = min(D,H);
        if(x1 < x2 && y1 < y2){
            area -= (x2-x1)*(y2-y1);
        }
        return area;
    }
};
