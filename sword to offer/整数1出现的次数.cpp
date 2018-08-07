class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n <= 0){
            return 0;
        }
        int count = 0;
        for(int i=1; i<=n; i*=10){
            int a = n/i;
            int b = n%i;
            count += (a+8)/10*i + (a%10 == 1)*(b+1);
        }
        return count;
    }
};
