//
// Created by 钟奇龙 on 2019-05-16.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int longestLengthOfIntegratableSubarray(vector<int> arr){
    if(arr.size() == 0) return 0;

    int maxLen = 0;
    set<int> s;

    for(int i=0; i<arr.size(); ++i){
        int maxValue = INT_MIN;
        int minValue = INT_MAX;
        for(int j=i; j<arr.size(); ++j){
            if(s.find(arr[j]) != s.end()){
                break;
            }
            s.insert(arr[j]);
            maxValue = max(maxValue,arr[j]);
            minValue = min(minValue,arr[j]);
            if(maxValue - minValue == j-i){
                maxLen = max(maxLen,j-i+1);
            }
        }
        s.clear();

    }
    return maxLen;
}

int main(){
    cout<<longestLengthOfIntegratableSubarray({5,5,3,2,6,4,3})<<endl;


    return 0;
}