// gfg problem  link of this problem -->https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1?utm_source=chatgpt.com
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>v){
        stack<int>st;
        int n  = v.size();
        for(int i = n - 1;i >= 0; i--){
            if(st.empty()){
                st.push(v[i]);
                v[i] = -1;
            }
            else{
                while(!st.empty()&&st.top()>=v[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    st.push(v[i]);
                    v[i] = -1;
                }
                else {
                    int  t =  st.top();
                    st.push(v[i]);
                    v[i] = t;;
                }
            }
        }
        return  v;
    }
    
};
