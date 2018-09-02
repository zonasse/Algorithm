class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for(long m = 1; m <= n; m *= 10){
            long a = n / m, b = n % m;
            count += (a + 8) / 10 * m;
            if(a % 10 == 1) count += b+1;
        }
        return count;
    }
};
