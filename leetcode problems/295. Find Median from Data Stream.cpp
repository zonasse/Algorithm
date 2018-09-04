class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        while(!smallHeap.empty()) smallHeap.pop();
        while(!bigHeap.empty()) bigHeap.pop();
    }

    void addNum(int num) {
        if(bigHeap.empty()){
            bigHeap.push(num);
            return;
        }
        if(bigHeap.size() == smallHeap.size()){
            if(num <= bigHeap.top()){
                bigHeap.push(num);
            }else{
                smallHeap.push(num);
            }
        }else if(bigHeap.size() == smallHeap.size() + 1){
            if(num <= bigHeap.top()){
                smallHeap.push(bigHeap.top());
                bigHeap.pop();
                bigHeap.push(num);
            }else{
                smallHeap.push(num);
            }
        }else{
            if(num >= smallHeap.top()){
                bigHeap.push(smallHeap.top());
                smallHeap.pop();
                smallHeap.push(num);
            }else{
                bigHeap.push(num);
            }
        }
    }

    double findMedian() {
        if(bigHeap.size() == smallHeap.size()){
            return 0.5*(bigHeap.top() + smallHeap.top());
        }else if(bigHeap.size() > smallHeap.size()){
            return bigHeap.top();
        }else{
            return smallHeap.top();
        }
    }
private:
    priority_queue<int,vector<int>, less<int> > bigHeap;
    priority_queue<int,vector<int>, greater<int> > smallHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
