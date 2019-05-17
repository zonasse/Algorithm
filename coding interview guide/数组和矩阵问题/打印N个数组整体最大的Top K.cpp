//
// Created by 钟奇龙 on 2019-05-16.
//

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int value;
    int arrNum;
    int index;
    Node(int value, int arrNum, int index):value(value),arrNum(arrNum),index(index){

    }
};
/*
 * 堆尾插入并向上调整
 */
void heapInsert(vector<Node*> &heap,int index){
    while(index != 0){
        int parent = (index-1)/2;
        if(heap[parent]->value < heap[index]->value){
            swap(heap[parent],heap[index]);
            index = parent;
        }else{
            break;
        }
    }
}
/*
 * 堆向下调整
 */
void heapify(vector<Node*> &heap,int index,int heapSize){
    int left = index*2 + 1;
    int right = index*2 + 2;
    while(left < heapSize){
        int largestIndex = index;
        largestIndex = heap[left]->value > heap[index]->value ? left:index;
        if(right < heapSize){
            largestIndex = heap[right]->value > heap[largestIndex]->value ? right:largestIndex;
        }
        if(largestIndex == index){
            break;
        }
        swap(heap[largestIndex],heap[index]);
        index = largestIndex;
        left = index*2 + 1;
        right = index*2 + 2;
    }
}
void printMaxTopK(vector<vector<int> > arr,int topK){
    if(arr.size() == 0 || arr[0].size() == 0) return;
    int heapSize = arr.size();
    vector<Node*> heap(heapSize);
    //将最大的N个数放入大根堆
    for(int i=0; i<arr.size(); ++i){
        Node *node = new Node(arr[i][arr[i].size()-1],i,arr[i].size()-1);
        heap[i] = node;
        heapInsert(heap,i);
    }
    for(int i=0; i<topK; ++i){
        if(heapSize == 0){
            break;
        }
        //打印大根堆顶
        cout<<heap[0]->value<<endl;
        if(heap[0]->index == 0){
            swap(heap[0],heap[--heapSize]);
            heapify(heap,0,heapSize);
        }else{
            Node *head = heap[0];
            heap[0] = new Node(arr[head->arrNum][head->index-1],head->arrNum,head->index-1);
            heapify(heap,0,heapSize);
        }
    }
}

int main(){
    vector<vector<int> > arr = {{219,405,538,845,971},{148,558},{52,99,348,691}};
    printMaxTopK(arr,7);
    return 0;
}