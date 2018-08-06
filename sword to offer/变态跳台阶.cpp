class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0){
            return -1;
        }
        if(number == 1){
            return 1;
        }
        return 2*jumpFloorII(number-1);
    }
};
