class Solution
{
public:
    void push(int node) {
        while(stack1.empty() == false){
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(node);
        while(stack2.empty() == false){
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop() {
        int x = stack1.top();
        stack1.pop();
        return x;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
