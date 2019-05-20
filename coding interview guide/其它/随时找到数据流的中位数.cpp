//
// Created by 钟奇龙 on 2019-05-20.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianHolder{
private:
    priority_queue<int,vector<int>,less<int> > maxHeap;
    priority_queue<int,vector<int>, greater<int> > minHeap;
    void modifyTwoHeapSize(){
        if(this->maxHeap.size() == this->minHeap.size() + 2){
            this->minHeap.push(this->maxHeap.top());
            this->maxHeap.pop();
        }else if(this->maxHeap.size() + 2 == this->minHeap.size()){
            this->maxHeap.push(this->minHeap.top());
            this->minHeap.pop();
        }
    }
public:
    MedianHolder(){

    }
    void addNumber(int num){
        if(maxHeap.empty()){
            maxHeap.push(num);
            return;
        }
        if(num <= maxHeap.top()){
            maxHeap.push(num);
        }else{
            if(minHeap.empty()){
                minHeap.push(num);
                return;
            }
            if(num >= minHeap.top()){
                minHeap.push(num);
            }else{
                maxHeap.push(num);
            }
        }
        this->modifyTwoHeapSize();
    }
    int getMedian(){
        if(this->maxHeap.size() + this->minHeap.size() == 0){
            return INT_MIN;
        }
        if((this->maxHeap.size() + this->minHeap.size()) % 2 == 0){
            return (this->maxHeap.top() + this->minHeap.top())/2;
        }else{
            return this->maxHeap.size() > this->minHeap.size() ? this->maxHeap.top():this->minHeap.top();
        }
    }
};

int main(){
    MedianHolder *holder = new MedianHolder();
    vector<int> arr = {3,1,5,6,3,7,2};
    for(int num:arr){
        holder->addNumber(num);
        cout<<holder->getMedian()<<endl;
    }
    return 0;
}
