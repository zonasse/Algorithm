class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2){
            return;
        }
        int temp = data[0];
        for(int i=1; i<data.size(); ++i){
            temp = temp ^ data[i];
        }
        if(temp == 0){
            return;
        }

        *num1 = 0;
        *num2 = 0;
        for(int i=0; i<data.size(); ++i){
            if(temp & data[i]){
                *num1 = *num1 ^ data[i];
            }else{
                *num2 = *num2 ^ data[i];
            }
        }
    }
};
