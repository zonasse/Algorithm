//
// Created by 钟奇龙 on 2019-05-07.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int merge(map<int,int> &m,int less,int more){
    int left = less-m[less]+1;
    int right = more+m[more]-1;
    int len = right-left+1;
    m[left] = len;
    m[right] = len;
    return len;
}
int longestConsecutive(vector<int> arr){
    if(arr.size() == 0) return 0;
    map<int,int> m;
    int maxLen = 0;
    for(int i=0; i<arr.size(); ++i){
        if(m.find(arr[i]) == m.end()){
            m[arr[i]] = 1;
            if(m.find(arr[i]-1) != m.end()){
                maxLen = max(maxLen,merge(m,arr[i]-1,arr[i]));
            }
            if(m.find(arr[i]+1) != m.end()){
                maxLen = max(maxLen,merge(m,arr[i],arr[i]+1));
            }
        }
    }
    return maxLen;
}

int main(){
    vector<int> arr = {100,4,200,1,3,2};
    cout<<longestConsecutive(arr)<<endl;
    return 0;
}