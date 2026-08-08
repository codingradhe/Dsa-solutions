// leetcode link of this problem -->> https://leetcode.com/problems/largest-rectangle-in-histogram/
// bruteforce folution 
// idea - (i) get next greater element and previous smaller element 
// with thier index and use formula of area = current*(nse - pse -1) for each element
class Solution {
public:
    vector<int> prevSmaller(vector<int>& v) {
        stack<pair<int,int>>st;
        int n = v.size();
        vector<int>ans(n);
        for(int i = 0;i<n;i++){
            if(st.empty()){
                st.push({v[i],i});
                ans[i] = -1;
            }
            else{
                while(!st.empty()&&st.top().first>=v[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push({v[i],i});
                    ans[i] = -1;
                }
                else {
                    ans[i] = st.top().second;
                    st.push({v[i],i});
                }
            }
        }
        return ans;
    }
    vector<int> nextSmallerEle(vector<int>v){
        stack<pair<int,int>>st;
        int n  = v.size();
        vector<int>ans(n);
        for(int i = n - 1;i >= 0; i--){
            if(st.empty()){
                st.push({v[i],i});
                ans[i] = n;
            }
            else{
                while(!st.empty()&&st.top().first>=v[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    st.push({v[i],i});
                    ans[i] = n;
                }
                else {
                    ans[i] = st.top().second;
                    st.push({v[i],i});
                }
            }
        }
        return  ans;
    }
    int largestRectangleArea(vector<int>& v){
        vector<int>nse,pse;
        int ans = 0,n = v.size();
        pse = prevSmaller(v);
        nse = nextSmallerEle(v);
        for(int i = 0;i < n; i++){
            ans  = max(ans , v[i]*(nse[i]-pse[i]-1));
        }
        return ans;
    }
};
// most optimal solution 
class Solution {
public:
    int largestRectangleArea(vector<int>& v){
        stack<int>st;
        int area = 0,n = v.size();
        for(int i = 0;i < n; i++){
           while(!st.empty()&&v[st.top()]>v[i]){
               int ele = st.top();
               st.pop();
               int nse = i,pse = st.empty() ? -1:st.top();
               area = max(area,v[ele]*(nse-pse-1));
           }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int ele = st.top();
            st.pop();
            int pse = st.empty() ? -1:st.top();
            area = max(area,v[ele]*(nse-pse-1));
        }
        return area;
    }
};
