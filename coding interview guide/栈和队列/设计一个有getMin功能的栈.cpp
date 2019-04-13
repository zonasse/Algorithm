#include <iostream>
#include <stack>
#include <exception>
using namespace std;

class MinStack{
public:
	void push(int newNum){
		if(min_stack.empty()){
			min_stack.push(newNum);
		}else if(newNum < getMin()){
			min_stack.push(newNum);
		}else{
			min_stack.push(getMin());
		}
		data_stack.push(newNum);
	}
	int pop(){
		if(data_stack.empty()){
			throw runtime_error("your stack is empty");
		}
		int num = data_stack.top();
		data_stack.pop();
		min_stack.pop();
		return num;
	}
	int getMin(){
		if(min_stack.empty()){
			throw runtime_error("your stack is empty");
		}
		return min_stack.top();
	}
	int top(){
		if(data_stack.empty()){
			throw runtime_error("your stack is empty");
		}
		return data_stack.top();
	}
private:
	stack<int> data_stack;
	stack<int> min_stack;
};

