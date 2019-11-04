/* 
用pair<first, second>数据结构，first记录data，second记录当前最小值
 */
class MinStack {
public:
    vector<pair<int, int>> min_stack;
    int min;
    /** initialize your data structure here. */
    MinStack() {
        min_stack.clear();
        min = INT_MAX;
    }
    
    void push(int x) {
        if (min_stack.empty())
            min = x;
        else
            min = (min_stack.back().second > x) ? x : min_stack.back().second;
        
        min_stack.push_back(pair<int, int>(x, min));
    }
    
    void pop() {
       min_stack.pop_back(); 
    }
    
    int top() {
        return min_stack.back().first;
    }
    
    int getMin() {
        return min_stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */