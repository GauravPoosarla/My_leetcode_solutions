class MyQueue {
public:
    stack <int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        int ans = input.top();
        input.pop();
        return ans;
    }
    
    int peek() {
        return input.top();
    }
    
    bool empty() {
        return input.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */