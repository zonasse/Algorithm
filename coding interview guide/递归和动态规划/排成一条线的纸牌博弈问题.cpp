//
// Created by 钟奇龙 on 2019-05-07.
//
#include <iostream>
#include <vector>
using namespace std;
int firstTake(vector<int> arr,int first,int last);

int lastTake(vector<int> arr,int first,int last){
    if(first == last){
        return 0;
    }else{
        return min(firstTake(arr,first+1,last),firstTake(arr,first,last-1));
    }
}
int firstTake(vector<int> arr,int first,int last){
    if(first == last){
        return arr[first];
    }else{
        return max(arr[first] + lastTake(arr,first+1,last),arr[last] + lastTake(arr,first,last-1));
    }
}

int win1(vector<int> arr){
    if(arr.size() == 0) return 0;
    return max(firstTake(arr,0,arr.size()-1),lastTake(arr,0,arr.size()-1));
}

int win2(vector<int> arr){
    if(arr.size() == 0) return 0;
    vector<vector<int> > firstTakeDP(arr.size(),vector<int>(arr.size()));
    vector<vector<int> > lastTakeDP(arr.size(),vector<int>(arr.size()));
    for(int last = 0; last < arr.size(); ++last){
        firstTakeDP[last][last] = arr[last];
        for(int first = last-1; first >= 0; --first){
            firstTakeDP[first][last] = max(arr[first] + lastTakeDP[first+1][last],arr[last] + lastTakeDP[first][last-1]);
            lastTakeDP[first][last] = min(firstTakeDP[first+1][last],firstTakeDP[first][last-1]);
        }
    }
    return max(firstTakeDP[0][arr.size()-1],lastTakeDP[0][arr.size()-1]);
}
int main(){
    vector<int> arr = {1,2,100,4};
    cout<<win1(arr)<<endl;
    cout<<win2(arr)<<endl;
    return 0;
}