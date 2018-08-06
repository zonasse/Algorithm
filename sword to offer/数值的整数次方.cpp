class Solution {
public:
    bool invalidInput = false;
    double Power(double base, int exponent) {
        invalidInput = false;
        if(equal(base,0.0) == true && exponent < 0){
            invalidInput = true;
            return 0.0;
        }
        int absExponent = exponent;
        if(exponent < 0){
            absExponent = -absExponent;
        }
        double ans = 1.0;
        for(int i=1; i<=absExponent; ++i){
            ans *= base;
        }
        if(exponent < 0){
            ans = 1.0/ans;
        }
        return ans;
    }
    bool equal(double num1,double num2){
        if(num1-num2 > -0.0000001 && num1-num2 < 0.0000001){
            return true;
        }
        return false;
    }
    double powerWithUnsignedExponent(double base,int exponent){
        if(exponent == 0){
            return 1;
        }
        if(exponent == 1){
            return base;
        }
        double result = powerWithUnsignedExponent(base,exponent >> 1);
        result *= result;
        if(exponent & 0x1 == 1){
            result *= base;
        }
        return result;
    }
};
