/*
 * 超时
 */
class Solution1 {
public:
    int findNthDigit(int n) {
        string s = "";
        for(int i=1; i<=n; ++i){
            s += to_string(i);
        }
        return s[n-1]-'0';
    }
};
/*
 * AC
 */
class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;
        while(n > len * cnt){
            n -= len*cnt;
            len++;
            cnt*=10;
            start*=10;
        }
        start += (n-1)/len;
        string t = to_string(start);
        return t[(n-1)%len]-'0';
    }
};