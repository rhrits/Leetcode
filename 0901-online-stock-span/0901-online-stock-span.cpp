class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span = 1;
        
        while(!stack_.empty() && price >= stack_.top().first){
            span += stack_.top().second;
            stack_.pop();
        }
        
        stack_.emplace(price, span);
        
        return span;
        
    }
    
private:
    stack<pair<int, int>> stack_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */