class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 1){
            return n;
        }
        int n1 = 1;
        int n2 = 1;
        for(int i=3; i<=n; ++i){
            int temp = n1+n2;
            n1 = n2;
            n2 = temp;
        }
        return n2;
    }
};
