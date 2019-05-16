//
// Created by 钟奇龙 on 2019-05-16.
//

#include <vector>
#include <iostream>
using namespace std;

bool isContain(vector<vector<int> > arr,int target){
    if(arr.size() == 0 || arr[0].size() == 0) return false;
    int row = 0;
    int col = arr.size()-1;
    while(row < arr.size() && col >= 0){
        if(arr[row][col] == target){
            return true;
        }else if(arr[row][col] > target){
            col--;
        }else{
            row++;
        }
    }
    return false;
}

int main(){
    vector<vector<int> > arr = {{0,1,2,5},{2,3,4,7},{4,4,4,8},{5,7,7,9}};
    cout<<isContain(arr,7)<<endl;
    cout<<isContain(arr,6)<<endl;

    return 0;
}