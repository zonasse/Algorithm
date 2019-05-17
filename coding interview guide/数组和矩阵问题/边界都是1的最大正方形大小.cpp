//
// Created by 钟奇龙 on 2019-05-17.
//

#include <iostream>
#include <vector>
using namespace std;
void setBorderMap(vector<vector<int> > matrix,vector<vector<int> > &right,vector<vector<int> > &down){
    int row = matrix.size();
    int col = matrix[0].size();
    if(matrix[row-1][col-1] == 1){
        right[row-1][col-1] = 1;
        down[row-1][col-1] = 1;
    }
    for(int i=row-2; i>=0; --i){
        if(matrix[i][col-1] == 1){
            right[i][col-1] = 1;
            down[i][col-1] = down[i+1][col-1]+1;
        }
    }
    for(int j=col-2; j>=0; --j){
        if(matrix[row-1][j] == 1){
            down[row-1][j] = 1;
            right[row-1][j] = right[row-1][j+1] + 1;
        }
    }
    for(int i=row-2; i>=0; --i){
        for(int j=col-2; j>=0; --j){
            if(matrix[i][j] == 1){
                down[i][j] = down[i+1][j] + 1;
                right[i][j] = right[i][j+1] + 1;
            }
        }
    }

}
bool hasSizeOfBorder(int size,vector<vector<int> > right,vector<vector<int> > down){
    for(int i=0; i<=right.size()-size; ++i){
        for(int j=0; j<=right[0].size()-size; ++j){
            if(right[i][j] >= size && down[i][j] >= size
            && right[i+size-1][j] >=size && down[i][j+size-1]>=size){
                return true;
            }
        }
    }
    return false;
}
int getMaxSize(vector<vector<int> > matrix){
    if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
    vector<vector<int> > right(matrix.size(),vector<int>(matrix[0].size()));
    vector<vector<int> > down(matrix.size(),vector<int>(matrix[0].size()));
    setBorderMap(matrix,right,down);
    for(int size = min(matrix.size(),matrix[0].size()); size > 0; --size){
        if(hasSizeOfBorder(size,right,down)){
            return size;
        }
    }
    return 0;
}

int main(){
    vector<vector<int> > matrix = {{0,1,1,1,1},{0,1,0,0,1},{0,1,0,0,1},{0,1,1,1,1},{0,1,0,1,1}};
    cout<<getMaxSize(matrix)<<endl;
    return 0;
}