class Solution {
public:
    vector<int> nextGreaterElements(vector<int>&v) {
        int n = v.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i = 2*n-1;i >= 0;i--){
            int idx = i%n;
            while(!st.empty()&& v[idx]>=st.top()){
                st.pop();
            }
            if(i<n){
                ans[idx] = st.empty() ? -1 : st.top();
            }
            st.push(v[i%n]);
        }
        return ans;
    }
};

