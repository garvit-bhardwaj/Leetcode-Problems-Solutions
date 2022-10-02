class MyQueue {
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()) {
            int x = output.top();
            output.pop();
            return x;
        } else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            int x = output.top();
            output.pop();
            return x;
        }
    }
    
    int peek() {
        if(!output.empty()) {
            return output.top();
        } else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};
