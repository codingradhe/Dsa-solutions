// 509. Fibonacci Number
// Solved
// Easy
// The Fibonacci numbers, commonly denoted F(n) form a sequence, 
// called the Fibonacci sequence, such that each number is the sum of the two preceding ones,
//   starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).crazy first time

 class Solution {
// 🤣🤣🤣🤣🤣 recursion method it looks 
    // int calc(int n, vector<int> &dp){
    //     if(dp[n] != -1) return dp[n];
    //     if(n == 0) return 0;
    //     if(n <= 2) return 1;
    //     int pre = calc(n - 1, dp);
    //     int ppre = calc( n - 2, dp);
    //     return dp[n] = pre + ppre;
    // }
public:
// 💕❤️❤️❤️ dp method memorization techenique
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int ans;
        int pre = 1, spre = 0;
        for(int i = 2; i <= n; i++){
            ans = pre + spre;
            spre = pre;
            pre = ans;
        }
        return ans;
    }
};
