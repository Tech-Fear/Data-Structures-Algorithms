class MinStack {
public:
    
    stack<pair<int,int>>st;
    MinStack() {
    }
    
    void push(int val) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int mini=st.empty()?val:min(val,st.top().second);
        st.push({val,mini});
    }
    void pop() {
        if(st.empty()) return;
        st.pop();
    }
    int top() {
        auto x=st.top();
       return  x.first;
    }
    
    int getMin() {
        auto x = st.top();
        return x.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */