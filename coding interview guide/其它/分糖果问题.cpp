//
// Created by 钟奇龙 on 2019-05-20.
//

#include <iostream>
#include <vector>
using namespace std;
/*
 * 原问题
 */
int candy(vector<int> ratings){
    if(ratings.size() == 0) return 0;
    vector<int> candy(ratings.size(),1);
    for(int i=0; i<ratings.size()-1; ++i){
        if(ratings[i+1] > ratings[i]){
            candy[i+1] = candy[i]+1;
        }
    }
    for(int i=ratings.size()-1; i>0; --i){
        if(ratings[i-1] > ratings[i]){
            candy[i-1] = max(candy[i-1],candy[i]+1);
        }
    }
    int res = 0;
    for(int i=0; i<candy.size(); ++i){
        res += candy[i];
    }
    return res;
}
/*
 * 进阶问题
 */
int candy2(vector<int> ratings){
    if(ratings.size() == 0) return 0;
    vector<int> candy(ratings.size(),1);
    for(int i=0; i<ratings.size()-1; ++i){
        if(ratings[i+1] > ratings[i]){
            candy[i+1] = candy[i]+1;
        }
        if(ratings[i+1] == ratings[i]){
            candy[i+1] = candy[i];
        }
    }
    for(int i=ratings.size()-1; i>0; --i){
        if(ratings[i-1] > ratings[i]){
            candy[i-1] = max(candy[i-1],candy[i]+1);
        }
        if(ratings[i-1] == ratings[i]){
            candy[i-1] = candy[i];
        }
    }
    int res = 0;
    for(int i=0; i<candy.size(); ++i){
        res += candy[i];
    }
    return res;
}
int main(){
    cout<<candy({1,4,5,9,3,2})<<endl;
    cout<<candy2({1,2,2})<<endl;
    cout<<candy2({1,2,3,3,2,1,0})<<endl;
    return 0;
}