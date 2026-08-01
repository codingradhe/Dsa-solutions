// ♥️♥️♥️♥️ to convert from string to int used functon --> stoi(str
// leetcode problem link of thiss problem -->https://leetcode.com/problems/baseball-game/?envType=problem-list-v2&envId=stack

class Solution {
public:
    int calPoints(vector<string>& v) {
        int n =v.size(), sum = 0,i = 0;
        stack<int>st;
        while(i<n){
            if(v[i]!="+"&&v[i]!="D"&&v[i]!="C"){
                st.push(stoi(v[i]));
                sum += stoi(v[i]);
            }
            else if(v[i] == "+"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.push(t1);
                st.push(t1+t2);
                sum += t1+t2;
            }
            else if(v[i] == "D"){
                int t1 = st.top();
                st.push(2*t1);
                sum += 2*t1;
            }
            else {
                int t1 = st.top();
                st.pop();
                sum -= t1;
            }
            i++;
        }
        return sum;
    }
};
