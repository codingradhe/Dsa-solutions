// ♥️♥️♥️♥️ always think about edge cases -- stack is empty or not ;
// leetcode link of this problem ---> https://leetcode.com/problems/valid-parentheses/?envType=study-plan&id=data-structure-i&utm_source=chatgpt.com
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push('(');
            } else if (s[i] == '[') {
                st.push('[');
            } else if (s[i] == '{') {
                st.push('{');
            } else if (s[i] == ')') {
                if (st.empty()||st.top() != '(') {
                    return false;
                } else {
                    st.pop();
                }
            }
            else if (s[i] == ']') {
                if (st.empty()||st.top() != '[') {
                    return false;
                } else {
                    st.pop();
                }
            }
            else if (s[i] == '}') {
                if (st.empty()||st.top() != '{') {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        if(st.size() ==0) return true;
        return false;
    }
};
