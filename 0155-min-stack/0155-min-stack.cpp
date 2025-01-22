class MinStack {
private:
    vector<vector<int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min_val = getMin();
        if(st.empty() || min_val > val)
            min_val = val;
        st.push_back({val, min_val});
    }
    
    void pop() {
        if(!st.empty())
            st.pop_back();
    }
    
    int top() {
        if(st.empty())
            return -1;
        return st.back()[0]; 
    }
    
    int getMin() {
        if(st.empty())
            return -1;
        return st.back()[1];
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