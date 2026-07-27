// ❤️❤️❤️ there is front , back and top  operation in queue

// leetcode problem link of this problem -->> https://leetcode.com/problems/implement-stack-using-queues/?envType=problem-list-v2&envId=queue
class MyStack {
public:
    queue<int>q;
    MyStack() {
    
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        for(int i = 0;i < n;i++){
            int a = q.front();
            q.pop();
            q.push(a);
        }
        return ;
    }
    
    int pop() {
        int b = q.front();
        q.pop();
        return b;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        if(q.empty()) return true;
        return false;
    }
};
