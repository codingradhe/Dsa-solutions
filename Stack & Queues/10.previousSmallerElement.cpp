// gfg problem link -->https://www.geeksforgeeks.org/problems/previous-smaller-element/1
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& v) {
        stack<int>st;
        int n = v.size();
        for(int i = 0;i<n;i++){
            if(st.empty()){
                st.push(v[i]);
                v[i] = -1;
            }
            else{
                while(!st.empty()&&st.top()>=v[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(v[i]);
                    v[i] = -1;
                }
                else {
                    int x = v[i];
                    v[i] = st.top();
                    st.push(x);
                }
            }
        }
        return v;
    }
};
