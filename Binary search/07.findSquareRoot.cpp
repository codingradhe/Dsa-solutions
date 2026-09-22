// 367. Valid Perfect Square
// Easy
// Given a positive integer num, return true if num
// is a perfect square or false otherwise.

// A perfect square is an integer that is the square
// of an integer. In other words, it is the product 
// of some integer with itself.

// You must not use any built-in library function, such
// as sqrt.
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 0,high = num;
        long long mid;
        while(low <= high){
            mid = low + (high - low)/2;
            long long compare = mid*mid;
            if(compare == num) return true;
            else if(compare < num) low = mid+1;
            else high = mid - 1;
        }
        return false;
    }
};
