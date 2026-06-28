class StockSpanner {
public:

    stack<int> st;  
    vector<int> ans; 

    StockSpanner() {
        
    }
    
    int next(int price) {
        int i = ans.size();

        ans.push_back(price);

        while(!st.empty() && price >= ans[st.top()]){
            st.pop();
        }

        int span = st.empty() ? i + 1 : i - st.top();

        st.push(i);

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */