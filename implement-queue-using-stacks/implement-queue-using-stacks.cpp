class MyQueue {
public:
  stack<int> st1,st2; 
    
  void push(int x){
    st1.push(x);
  }
    
  int pop(){
    while(!st1.empty()) {st2.push(st1.top()); st1.pop();}
    int x = st2.top();
    st2.pop();
    while(!st2.empty()) {st1.push(st2.top()); st2.pop();}
    return x;
  }
    
  int peek(){
    while(!st1.empty()) {st2.push(st1.top()); st1.pop();}
    int x = st2.top();
    while(!st2.empty()) {st1.push(st2.top()); st2.pop();}
    return x;
  }
    
  bool empty() {
    return st1.empty();
  }
};