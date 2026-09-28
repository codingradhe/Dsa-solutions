// 162. Find Peak Element
// Medium
// A peak element is an element that is strictly greater
// than its neighbors.

// Given a 0-indexed integer array nums, find a peak 
// element, and return its index. If the array contains
// multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other
// words, an element is always considered to be strictly greater
// than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.


// ♥️♥️♥️🎊🎉  A wonderful confusion will arrived when see this solution how actually this problem works
// but when i observe that there will be three sondition for mid 
// (1)  nums[mid] > nums[mid +1] so end or high = mid;
// nums[mid] < nums[mid + 1] so low = mid = 1
 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        int end = n - 1;

        while(start < end) {
            int mid = start + (end - start) / 2;

            if(nums[mid] < nums[mid + 1]) {
                // We are on an increasing slope
                start = mid + 1;
            }
            else {
                // We are on a decreasing slope
                end = mid;
            }
        }

        return start;
    }
};
