// 659. Split Array into Consecutive Subsequences
// Medium
// You are given an integer array nums that is sorted in 
// non-decreasing order.

// Determine if it is possible to split nums into one or
// more subsequences such that both of the following 
// conditions are true:

// Each subsequence is a consecutive increasing sequence
// (i.e. each integer is exactly one more than the 
// previous integer).
// All subsequences have a length of 3 or more.
// Return true if you can split nums according to the
// above conditions, or false otherwise.

// A subsequence of an array is a new array that is
// formed from the original array by deleting some 
// (can be none) of the elements without disturbing the relative positions
// of the remaining elements. (i.e., [1,3,5] is
// a subsequence of [1,2,3,4,5] while 
// [1,3,2] is not).
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> need;

        for (int x : nums) {
            freq[x]++;
        }

        for (int x : nums) {

            // Already used
            if (freq[x] == 0)
                continue;

            // Use x
            freq[x]--;

            // Extend an existing subsequence
            if (need[x] > 0) {
                need[x]--;
                need[x + 1]++;
            }

            // Start a new subsequence
            else {
                if (freq[x + 1] > 0 && freq[x + 2] > 0) {
                    freq[x + 1]--;
                    freq[x + 2]--;

                    need[x + 3]++;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};


