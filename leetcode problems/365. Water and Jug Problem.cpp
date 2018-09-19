class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x+y >= z && z%gcd(x,y) == 0);
    }
    int gcd(int x,int y){
        if(!y) return x;
        return gcd(y,x%y);
    }
};
