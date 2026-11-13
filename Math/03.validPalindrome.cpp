// 125. Valid Palindrome
// Solved
// Easy
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
// and removing all non-alphanumeric characters, it reads the same forward and backward. 
//   Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 class Solution {
    bool palindrome(string x) {
        int n = x.size();
        if(n <= 1) return true;
        for(int i = 0; i < n / 2; i++) {
            if (x[i] != x[n - 1 - i])
                return false;
        }
        return true;
    }

public:
    bool isPalindrome(string s) {          //    ❤️❤️❤️❤️❤️❤️❤️❤️❤️😍🤣🤣👌numeric character = a-z . A - Z and 0 - 9
        string temp = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if(c >= 'a' && c <= 'z') temp += c;
            else if(c >= 'A' && c <= 'Z') temp += tolower(c);
            else if( c >= '0' && c <= '9') temp += c;
            else continue;
        }
        return palindrome(temp);
    }
};
