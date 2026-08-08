// leetcode link of problem-->https://leetcode.com/problems/remove-k-digits/
class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        while(s[0]=='0'){
            s.erase(0,1);
        }
        n = s.size();
        if(k>=s.size()) return "0";
        stack<int>st;
        for(int i = 0;i <n;i++){
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }
            while(!st.empty()&&k>0&&st.top()>s[i]){
                st.pop(),k--;
            }
            st.push(s[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        s.clear();
        while(!st.empty()){
            s += st.top(),st.pop();
        }
        n = s.size();
        int i = 0;
        while(i<n/2){
            swap(s[i],s[n-i-1]);
            i++;
        }
        while(s[0]=='0'){
            s.erase(0,1);
        }
        if(s.size() ==0) return "0";
        return s;
    }
};






