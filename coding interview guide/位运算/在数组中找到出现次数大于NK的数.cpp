//
// Created by 钟奇龙 on 2019-05-14.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
 * 出现次数超过一半的数
 */
void printHalfMajorNumber(vector<int> arr){
    int times = 0;
    int cur = 0;
    for(int i=0; i<arr.size(); ++i){
        if(times == 0){
            cur = arr[i];
            times++;
        }else{
            if(arr[i] == cur){
                times++;
            }else{
                times--;
            }
        }

    }
    times = 0;
    for(int i=0; i<arr.size(); ++i){
        if(arr[i] == cur) times++;
    }
    if(times > arr.size()/2){
        cout<<cur<<endl;
    }else{
        cout<<"no such number"<<endl;
    }
}
/*
 * 出现次数超过N/K次的数
 */
void candidatesAllMinusOne(map<int,int> &candidates_map){
    vector<int> removeKeys;
    for(auto &it : candidates_map){
        if(it.second == 1){
            removeKeys.push_back(it.first);
        }else{
            it.second = it.second-1;
        }
    }
    for(int i=0; i<removeKeys.size(); ++i){
        candidates_map.erase(candidates_map.find(removeKeys[i]));
    }
}
void printKMajor(vector<int> arr,int k){
    if(k < 2){
        cout<<"invalid k"<<endl;
        return;
    }
    map<int,int> candidates_map;
    for(int i=0; i<arr.size(); ++i){
        if(candidates_map.find(arr[i]) != candidates_map.end()){
            candidates_map[arr[i]]++;
        }else{
            if(candidates_map.size() == k-1){
                candidatesAllMinusOne(candidates_map);
            }else{
                candidates_map[arr[i]] = 1;
            }
        }
    }
    //检查候选键哈希表中的元素是否符合要求

    //将哈希表所有元素次数置0
    for(auto &it : candidates_map){
        it.second = 0;
    }
    //重新累计次数
    for(int i=0; i<arr.size(); ++i){
        if(candidates_map.find(arr[i]) != candidates_map.end()){
            candidates_map[arr[i]]++;
        }
    }
    bool flag = false;
    for(auto it : candidates_map){
        if(it.second > arr.size()/k){
            flag = true;
            cout<<it.first<<endl;
        }
    }
    if(!flag){
        cout<<"no such number"<<endl;
    }
}
int main(){
//    printHalfMajorNumber({1,2,3,4,3,3,3});
    printKMajor({1,2,3,4,4,4,3,3,3},3);

    return 0;
}