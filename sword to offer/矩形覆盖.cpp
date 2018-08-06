class Solution {
public:
    int rectCover(int number) {
        if(number <= 2){
            return number;
        }
        int n1 = 1;
        int n2 = 2;
        for(int i=3; i<=number; ++i){
            int temp = n1 + n2;
            n1 = n2;
            n2 = temp;
        }
        return n2;
    }
};
