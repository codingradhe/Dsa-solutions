// 7. Reverse Integer
// Solved
// Medium
// Given a signed 32-bit integer x, return x with its digits reversed. 
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        int sign = 1;
        if(x < 0) sign = -1;
        long long num = abs(static_cast<long long>(x));
        long long rev = 0;
        int maxi = INT_MAX, mini = INT_MIN;
        while(num){
            long long rem = num % 10;
            rev = rev * 10 + rem;
            if(rev > maxi || rev < mini) return 0;
            num /= 10;
        }
        return static_cast<int> (rev) * sign;
    }
};
