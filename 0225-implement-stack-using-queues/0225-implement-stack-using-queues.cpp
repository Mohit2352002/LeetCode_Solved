static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();



/*
class MyStack {
	queue<int>q;
public:
    MyStack() {
    }
    
    void push(int x) {
			q.push(x);
			for(int i=q.size()-1;i>0;--i){
				q.push(q.front());
				q.pop();
			}
    }
    
    int pop() {
			// if(q.empty()) return -1;
			int tp=q.front();
			q.pop();
			return tp;
    }
    
    int top() {
		// if(q.empty()) return -1;
			return q.front();
    }
    
    bool empty() {
			return q.size()==0;
    }
};*/



class MyStack {
    queue<int>q1,q2;
public:
    MyStack() {
    }
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
    }
    int top() {
        return q1.front();
    }
    bool empty() {
        return q1.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */