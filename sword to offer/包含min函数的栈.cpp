class Solution {
public:
    void push(int value) {
        dataStack.push(value);
        if(_minStack.empty()){
            _minStack.push(value);
        }else{
            if(value < _minStack.top()){
                _minStack.push(value);
            }else{
                _minStack.push(_minStack.top());
            }
        }
    }
    void pop() {
        dataStack.pop();
        _minStack.pop();
    }
    int top() {
        return dataStack.top();
    }
    int min() {
        return _minStack.top();
    }
private:
    stack<int> dataStack;
    stack<int> _minStack;
};
