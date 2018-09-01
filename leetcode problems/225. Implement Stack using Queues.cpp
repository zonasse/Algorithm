class MyStack1 {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        std::queue<int> tempQueue;
        tempQueue.push(x);
        while(_data.empty() == false){
            tempQueue.push(_data.front());
            _data.pop();
        }
        while(tempQueue.empty() == false){
            _data.push(tempQueue.front());
            tempQueue.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        int x = _data.front();
        _data.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return _data.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _data.empty();
    }
    private:
        std::queue<int> _data;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
class MyStack2 {
private:
    queue<int> data;
    queue<int> support;
public:
    /** Initialize your data structure here. */
    MyStack() {
        while(data.empty() == false) data.pop();
        while(data.empty() == false) support.pop();
    }

    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(data.size() > 1){
            support.push(data.front());
            data.pop();
        }
        int x = data.front();
        data.pop();
        while(support.empty() == false){
            data.push(support.front());
            support.pop();
        }
        return x;
    }

    /** Get the top element. */
    int top() {
        while(data.size() > 1){
            support.push(data.front());
            data.pop();
        }
        int x = data.front();
        support.push(x);
        data.pop();
        while(support.empty() == false){
            data.push(support.front());
            support.pop();
        }
        return x;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
