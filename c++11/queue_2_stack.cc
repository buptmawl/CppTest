#include <queue> 
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        //que_one.clear();
        //que_two.clear();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
       top_val = x;
       if (!que_one.empty()) { 
       		que_one.push(x);
       } else {
       		que_two.push(x);
       }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {

    	while(!que_one.empty()) {
    		int x = que_one.front();
    		que_one.pop();
    		if (!que_one.empty()) {
				que_two.push(x);
       			top_val = x;
    		} else {
    			return x;
    		}
    	}

    	while(!que_two.empty()) {
    		int x = que_two.front();
    		que_two.pop();
    		if (!que_two.empty()) {
				que_one.push(x);
       			top_val = x;
    		} else {
    			return x;
    		}
    	}
    }
    
    /** Get the top element. */
    int top() {
    	return top_val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
    	if (que_one.empty() && que_two.empty()) {
    		return true;
    	}
    	return false;
    }

private:
	std::queue<int> que_one;
	std::queue<int> que_two;
	int top_val;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
