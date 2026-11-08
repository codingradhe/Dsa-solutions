// 5. Longest Palindromic Substring
// Medium
// Given a string s, return the longest palindromic substring in s.

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

class Solution {
public:
    bool ispalindrome(string s) {
        int n = s.size();

        for(int i = 0; i < n / 2; i++) {
            if(s[i] != s[n - 1 - i])
                return false;
        }

        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        for(int i = 0; i < n; i++) {

            string st = s.substr(i, n - i);

            while(!st.empty()) {
                int size = st.size();

                if(st[0] == st[size - 1] && ispalindrome(st)) {
                    if(st.size() > ans.size()) {
                        ans = st;
                    }
                    break;
                }
                if(ans.size() > st.size()) break;

                st.pop_back();
            }
        }

        return ans;
    }
};
