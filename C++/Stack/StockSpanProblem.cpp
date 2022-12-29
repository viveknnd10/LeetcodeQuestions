class StockSpanner {
public:
stack<pair<int,int>> currentSpan;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        while(!currentSpan.empty() && (currentSpan.top()).first<=price)
        {
            count+=(currentSpan.top()).second;
            currentSpan.pop();
        }
        currentSpan.push({price,count});
        return count;
    }
};