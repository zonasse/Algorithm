//
// Created by 钟奇龙 on 2019-05-17.
//

#include <vector>
#include <iostream>
using namespace std;

vector<int> product1(vector<int> arr){
    if(arr.size() < 2) return {};
    int countOfZero = 0;
    int all = 1;
    for(int i=0; i<arr.size(); ++i){
        if(arr[i] != 0){
            all *= arr[i];
        }else{
            countOfZero++;
        }
    }
    vector<int> res(arr.size(),0);
    if(countOfZero == 0){
        for(int i=0; i<arr.size(); ++i){
            res[i] = all/arr[i];
        }
    }
    if(countOfZero == 1){
        for(int i=0; i<arr.size(); ++i){
            if(arr[i] != 0){
                res[i] = all;
            }
        }
    }
    return res;
}
vector<int> product2(vector<int> arr){
    if(arr.size() < 2) return {};
    vector<int> res(arr.size(),0);
    res[0] = arr[0];
    for(int i=1; i<arr.size(); ++i){
        res[i] = res[i-1] * arr[i];
    }
    int temp = 1;
    for(int i=arr.size()-1; i>0; --i){
        res[i] = res[i-1] * temp;
        temp *= arr[i];
    }
    res[0] = temp;
    return res;
}
int main(){
    vector<int> res = product2({2,3,1,4});

    return 0;
}