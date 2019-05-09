//
// Created by 钟奇龙 on 2019-05-09.
//
#include <vector>
#include <iostream>
using namespace std;
/*
 * 解法1，普通哈希解法
 */
bool isUnique1(vector<char> arr){
    bool mark[256];
    memset(mark,false,sizeof(mark));
    for(int i=0; i<arr.size(); ++i){
        if(mark[arr[i]] == true){
            return false;
        }else{
            mark[arr[i]] = true;
        }
    }
    return true;
}
/*
 * 解法二：堆排序
 */
void heapInsert(vector<char> &arr,int index){
    while(index != 0){
        int parent = (index-1)/2;
        if(arr[parent] < arr[index]){
            swap(arr[parent],arr[index]);
            index = parent;
        }else{
            break;
        }
    }
}
void heapify(vector<char> &arr,int index){
    int left = index*2;
    int right = index*2+1;
    int largest = index;
    while(left < arr.size()){
        if(arr[left] > arr[index]){
            largest = left;
        }
        if(right < arr.size() && arr[right] > arr[largest]){
            largest = right;
        }
        if(largest != index){
            swap(arr[largest],arr[index]);
        }else{
            break;
        }
        index = largest;
        left = index * 2;
        right = index * 2 + 1;
    }
}
void heapSort(vector<char> &arr){
    for(int i=0; i<arr.size(); ++i){
        heapInsert(arr,i);
    }
    for(int i=arr.size()-1; i>=0; --i){
        swap(arr[i],arr[0]);
        heapify(arr,i);
    }
}

bool isUnique2(vector<char> &arr){
    heapSort(arr);
    for(int i=1; i<arr.size(); ++i){
        if(arr[i] == arr[i-1]) return false;
    }
    return true;
}

int main(){
    vector<char> arr = {'a','b','c','d','a'};
    cout<<isUnique2(arr)<<endl;

    return 0;
}