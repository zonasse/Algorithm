class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while(data.empty() == false){
            support.push(data.top());
            data.pop();
        }
        data.push(x);
        while(support.empty() == false){
            data.push(support.top());
            support.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = data.top();
        data.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        return data.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
private:
    stack<int> data;
    stack<int> support;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
