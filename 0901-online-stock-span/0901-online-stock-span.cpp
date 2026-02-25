class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx;
    StockSpanner() {
        idx = -1;
    }
    
    int next(int price) {
        idx++;
        while(!st.empty() && price >= st.top().first) 
            st.pop();
        int res = -1;
        if(!st.empty())
            res = idx - st.top().second;
        else
            res = idx+1;
        st.push({price, idx});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */