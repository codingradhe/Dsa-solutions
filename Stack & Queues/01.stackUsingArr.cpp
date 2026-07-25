class stimp{
  public:
    int  topidx = -1,st[10];
    void push(int x){
      if(topidx == 9) return;
      st[++topidx] = x;
      return;
    }
    void pop(){
      if(topidx == -1) return;
      topidx--;
      return;
    }
    int size(){
      return topidx+1;
    }
    int top(){
      if(topidx == -1) return -1;
      return st[topidx];
    }
    bool empty(){
      return topidx == -1;
    }
};
