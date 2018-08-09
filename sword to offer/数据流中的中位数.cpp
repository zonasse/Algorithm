class Solution {
public:
    Solution(){
        while(!maxHeap.empty()) maxHeap.pop();
        while(!minHeap.empty()) minHeap.pop();
    }
    void Insert(int num){
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        if(maxHeap.size() == minHeap.size()+2){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(maxHeap.size()+1 == minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double GetMedian(){
        if(maxHeap.size()+minHeap.size() == 0){
            return NULL;
        }
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top()+minHeap.top())/2.0;
        }else{
            return maxHeap.top();
        }


    }

private:
    priority_queue<int,vector<int> ,greater<int> > minHeap;//保存大一半元素
    priority_queue<int,vector<int> ,less<int> > maxHeap;//保存小一半元素
};
