// 1539. Kth Missing Positive Number
// Easy
// Given an array arr of positive integers sorted in a
// strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from
// this array.
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int miss = arr[mid] - mid - 1;

            if(miss < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low + k;
    }
};
