class Solution1 {
public:
     int  NumberOf1(int n) {
         int ans = 0;
         while(n){
             ans++;
             n = (n-1) & n;
         }
         return ans;
     }

};
class Solution2 {
public:
     int  NumberOf1(int n) {
         int ans = 0;
         int flag = 1;
         while(flag){
             if(n & flag){
                 ans++;
             }
             flag = flag << 1;
         }
         return ans;
     }

};
