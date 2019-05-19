//
// Created by 钟奇龙 on 2019-05-19.
//
#include <iostream>
#include <map>
using namespace std;

class RandomPool{
private:
    int size;
    map<int,int> keyIndexMap;
    map<int,int> indexKeyMap;

public:
    RandomPool(int size):size(size){

    }
    void insert(int key){
        if(this->keyIndexMap.find(key) == this->keyIndexMap.end()){
            this->keyIndexMap[key] = this->size;
            this->indexKeyMap[this->size++] = key;
        }
    }
    void del(int deleteKey){
        if(this->keyIndexMap.find(deleteKey) != this->keyIndexMap.end()){
            int deleteIndex = this->keyIndexMap[deleteKey];
            int lastIndex = --this->size;
            int lastKey = this->indexKeyMap[lastIndex];

            this->keyIndexMap[lastKey] = deleteIndex;
            this->indexKeyMap[deleteIndex] = lastKey;

            this->keyIndexMap.erase(this->keyIndexMap.find(deleteKey));
            this->indexKeyMap.erase(this->indexKeyMap.find(lastIndex));
        }
    }
    int getRandom(){
        if(this->size == 0) return INT_MIN;
        return this->indexKeyMap[rand() % this->size];
    }
};