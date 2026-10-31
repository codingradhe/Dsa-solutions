//8. String to Integer (atoi)
// Solved
// Medium
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-'
//   or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit 
// character is encountered or the end of the string is reached. If no digits 
// were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1],
// then round the integer to remain in the range. Specifically, integers less than -231
// should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.
// Note:​​​​​​​ You must not use any built-in library function that converts a string to a number 
// (for example, atoi, stoi, Integer.parseInt, int(), parseInt, Number()). Perform the conversion manually.
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Determine sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Convert digits
        long long ans = 0;

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            ans = ans * 10 + digit;

            // 4. Handle overflow
            if (sign == 1 && ans > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -ans < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return (int)(sign * ans);
    }
};
