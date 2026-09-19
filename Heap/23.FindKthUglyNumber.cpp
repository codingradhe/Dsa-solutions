// 264. Ugly Number II
// Medium
// An ugly number is a positive integer whose prime
// factors are limited to 2, 3, and 5.

// Given an integer n, return the nth ugly number.
// Example 1:
// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 
//   is the sequence of the first 10 ugly numbers.
class Solution {
public:
    int nthUglyNumber(int n) {
        long long currugly = 1;
        set<long long>st;
        st.insert(1);
        for(int i = 0;i < n;i++){
            currugly = *st.begin();
            st.erase(st.begin());
            st.insert(currugly*2);
            st.insert(currugly*3);
            st.insert(currugly*5);
        }
        static_cast<int>(currugly);
        return currugly;
    }
};

