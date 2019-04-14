//
// Created by 钟奇龙 on 2019-04-14.
//
#include <deque>
#include <vector>
#include <iostream>
using namespace std;

vector<int> getMaxWindow(vector<int> arr,int w){
    vector<int> res;
    if(arr.empty() || w < 1 || arr.size() < w){
        return res;
    }
    deque<int> qmax;

    for (int i = 0; i < arr.size(); ++i) {
        while(qmax.empty() == false && arr[i] >= arr[qmax.back()]){
            qmax.pop_back();
        }
        qmax.push_back(i);
        if(qmax.front() == i-w){
            qmax.pop_front();
        }
        if(i >= w-1){
            res.push_back(arr[qmax.front()]);
        }
    }
    return res;
}

int main(){
    vector<int> arr = {4,3,5,4,3,3,6,7};
    vector<int> maxWindw = getMaxWindow(arr,3);
    for (int i = 0; i < maxWindw.size(); ++i) {
        cout<<maxWindw[i]<<endl;
    }
}
