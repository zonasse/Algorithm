//
// Created by 钟奇龙 on 2019-05-03.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int setPos(vector<int> preArray,int pLeft,int pRight,vector<int> inArray,int iLeft,int iRight,vector<int> &posArray,int posIndex,map<int,int> m){
    if(pLeft > pRight) return posIndex;
    posArray[posIndex--] = preArray[pLeft];
    int headIndex = m[preArray[pLeft]];
    posIndex = setPos(preArray,pRight-iRight+headIndex+1,pRight,inArray,headIndex+1,iRight,posArray,posIndex,m);
    return setPos(preArray,pLeft+1,pLeft+headIndex-iLeft,inArray,iLeft,headIndex-1,posArray,posIndex,m);
}
vector<int> getPosArray(vector<int> preArray, vector<int> inArray){
    int length = preArray.size();
    vector<int> posArray(length);
    map<int,int> m;
    for (int i = 0; i < length; ++i) {
        m[inArray[i]] = i;
    }
    setPos(preArray,0,length-1,inArray,0,length-1,posArray,length-1,m);
    return posArray;
}

int main(){
    vector<int> preArray = {1,2,4,5,3,6,7};
    vector<int> inArray = {4,2,5,1,6,3,7};
    vector<int> posArray = getPosArray(preArray,inArray);
    return 0;
}