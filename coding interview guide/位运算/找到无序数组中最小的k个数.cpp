//
// Created by 钟奇龙 on 2019-05-13.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;
/*
 * 堆排序的方法
 */
void heapInsert(vector<int> &heap,int index,int num){
    heap[index] = num;
    while(index != 0){
        int parentIndex = (index-1)/2;
        if(heap[parentIndex] > heap[index]){
            swap(heap[parentIndex],heap[index]);
            index = parentIndex;
        }else{
            break;
        }
    }
}
void heapify(vector<int> &heap,int index){
    int left = 0;
    int right = 0;
    while(left != heap.size()){
        left = index*2;
        right = index*2+1;
        int largestIndex = heap[left] > heap[index] ? left:index;
        if(right < heap.size() && heap[right] > heap[largestIndex]){
            largestIndex =  right;
        }
        if(largestIndex == index) break;
        swap(heap[largestIndex],heap[index]);
        index = largestIndex;
    }
}
vector<int> getMinKNums(vector<int> arr,int k){
    if(arr.size() <= k) return arr;
    //维护一个大根堆
    vector<int> heap(k);
    for(int i=0; i<k; ++i){
        heapInsert(heap,i,arr[i]);
    }
    for(int i=k; i<arr.size(); ++i){
        if(arr[i] < heap[0]){
            heap[0] = arr[i];
            heapify(heap,0);
        }
    }
    return heap;
}

int main(){
    vector<int> arr = {4,3,6,2,7,8,4,3,2,1};
    vector<int> minKNums = getMinKNums(arr,3);

    return 0;
}