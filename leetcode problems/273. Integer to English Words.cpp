class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string res = "";
        if(num < 0){
            res += "Negtive ";
        }
        if(num == INT_MIN){
            res += "Two Billion ";
            num %= -2000000000;
        }
        num = abs(num);
        int high = 1000000000;
        int highIndex = 0;
        vector<string> names = {"Billion ","Million ","Thousand ",""};
        while(num){
            int cur = num / high;
            num %= high;
            if(cur){
                res += number1To999(cur);
                res += names[highIndex];
            }
            highIndex++;
            high /= 1000;
        }
        if(res.back() == ' ') res.pop_back();
        return res;
    }
    string number1To19(int num){
        if(num < 1 || num > 19) return "";
        vector<string> names = {"One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
        return names[num-1];
    }
    string number1To99(int num){
        if(num < 1 || num > 99) return "";
        if(num < 20){
            return number1To19(num);
        }
        int high = num / 10;
        vector<string> tyNames = {"Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
        return tyNames[high-2] + number1To19(num%10);
    }
    string number1To999(int num){
        if(num < 1 || num > 999) return "";
        if(num  < 100){
            return number1To99(num);
        }
        int high = num / 100;
        return number1To19(high) + "Hundred " + number1To99(num % 100);
    }
};
