class Solution {
public:
    bool isNumeric(char* string){
        int i = 0;
        int status = 0;
        //6ÖÖ×´Ì¬
        while(status != 6){
            switch(status){
                case 0:{
                    if(string[i] == '+' || string[i] == '-' || isNum(string[i])){
                        status = 1;
                    }else{
                        return false;
                    }
                }
                break;
                case 1:{
                    if(isNum(string[i])){
                        status = 1;
                    }else if(string[i] == '.'){
                        status = 2;
                    }else if(string[i] == 'e' || string[i] == 'E'){
                        status = 4;
                    }else if(string[i] == '\0'){
                        status = 6;
                    }else{
                        return false;
                    }
                }
                break;
                case 2:{
                    if(isNum(string[i])){
                        status = 3;
                    }else if(string[i] == '\0'){
                        status = 6;
                    }else{
                        return false;
                    }
                }
                break;
                case 3:{
                    if(isNum(string[i])){
                        status = 3;
                    }else if(string[i] == 'e' || string[i] == 'E'){
                        status = 4;
                    }else if(string[i] == '\0'){
                        status = 6;
                    }else{
                        return false;
                    }
                }
                break;
                case 4:{
                    if(string[i] == '+' || string[i] == '-' || isNum(string[i])){
                        status = 5;
                    }else{
                        return false;
                    }
                }
                break;
                case 5:{
                    if(isNum(string[i])){
                        status = 5;
                    }else if(string[i] == '\0'){
                        return true;
                    }else{
                        return false;
                    }
                }
                break;
            }
            ++i;
        }
        return true;
    }
    bool isNum(char ch){
        return ch >= '0' && ch <= '9';
    }

};
