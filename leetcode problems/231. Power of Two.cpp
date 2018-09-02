class Solution1 {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int count_of_1 = 0;
        while(n){
            if(n & 1 == 1) count_of_1++;
            if(count_of_1 > 1) break;
            n = n >> 1;
        }
        return count_of_1 == 1;
    }
};
class Solution2 {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};
