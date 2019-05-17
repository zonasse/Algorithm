//
// Created by 钟奇龙 on 2019-05-17.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minPathValue(vector<vector<int> > arr){
    if(arr.size() == 0 || arr[0].size() == 0) return 0;
    vector<vector<int> > map(arr.size(),vector<int>(arr[0].size(),0));
    map[0][0] = 1;
    //存放行、列值
    queue<pair<int,int> > Q;
    Q.push(make_pair(0,0));
    while(Q.empty() == false){
        int row = Q.front().first;
        int col = Q.front().second;
        Q.pop();
        if(row == arr.size()-1 && col == arr[0].size()-1){
            return map[row][col];
        }
        static const vector<int> dx = {-1,1,0,0};
        static const vector<int> dy = {0,0,-1,1};
        for(int i=0; i<4; ++i){
            int nextX = row + dx[i];
            int nextY = col + dy[i];
            if(nextX >= 0 && nextX < arr.size() && nextY >=0 && nextY < arr[0].size()
            && map[nextX][nextY] == 0 && arr[nextX][nextY] == 1){
                Q.push(make_pair(nextX,nextY));
                map[nextX][nextY] = map[row][col] + 1;
            }
        }
    }
    return 0;
}

int main(){
    vector<vector<int> > arr = {{1,0,1,1,1},{1,0,1,0,1},{1,1,1,0,1},{0,0,0,0,1}};
    cout<<minPathValue(arr)<<endl;
    return 0;
}