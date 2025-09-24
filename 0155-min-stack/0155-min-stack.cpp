class MinStack {
public:
     stack<long long> st;
     long long min;
    MinStack() { // constructor
        min = LLONG_MAX;
        
    }
    
    void push(int val) { // 0(1)
        long long x = (long long)val;
        if(st.size()==0){
            st.push(x);
            min = x;
        }
        else if(x>=min) st.push(val);
        else{ // val < min
             st.push(2*x-min);
             min = x;
        }
    }
    
    void pop() { //0(1)
    if(st.top()<min){ // A fake value is present
       // before popping make sure to retrive the old min
       long long oldMan = 2*min - st.top();
       min = oldMan;

    }
    st.pop();
        
    }
    
    int top() { // 0(1)
         if(st.top()<min) return min;
         else return st.top();
        
    }
    
    int getMin() { //0(1)
    return min;
        
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