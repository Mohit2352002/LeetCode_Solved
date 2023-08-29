static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();



/*
class MyQueue {
    stack<int>input,output;
public:
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int x=output.top();
            output.pop();
            return x;
        }else{
            while(input.size()!=1){
                output.push(input.top());
                input.pop();
            }
            int x=input.top();
            input.pop();
            return x;
        }
    }
    
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return (output.size()==0 and input.size()==0);
    }
};*/




class MyQueue {
    stack<int>s1,s2;
public:
    MyQueue() {
    }
    
    void push(int x) {
        if(s1.empty()) {
            s1.push(x);
            return;
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        int x=s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.size()==0;
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