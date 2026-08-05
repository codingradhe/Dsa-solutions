// leetcode link of this problem-->>https://leetcode.com/problems/asteroid-collision/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        int n = v.size();
        stack<int>st;
        for(int i = 0;i < n;i++){
            if(st.empty()||v[i]>0){
                st.push(v[i]);
            }
            else{
                bool destroy = false;
                while(!st.empty()&&st.top()>0){
                    if(abs(v[i])>st.top()){
                        st.pop();
                    }
                    else if(abs(v[i])==st.top()){
                        st.pop();
                        destroy = true;
                        break;
                    }
                    else{
                        destroy = true;
                        break;
                    }
                }
                if (!destroy && (st.empty() || st.top() < 0))
    st.push(v[i]);
            }
        }
        v.clear();
        n = st.size();
        for(int i = 0;i < n;i++){
            int t = st.top();
            st.pop();
            v.push_back(t);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
