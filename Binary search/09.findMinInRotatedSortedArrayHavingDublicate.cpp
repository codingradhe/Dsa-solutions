// 154. Find Minimum in Rotated Sorted Array II
// Hard
// Suppose an array of length n sorted in ascending
// order is rotated between 1 and n times. For example
//   , the array nums = [0,1,4,4,5,6,7] might become:

// [4,5,6,7,0,1,4] if it was rotated 4 times.
// [0,1,4,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1],
// a[2], ..., a[n-1]] 1 time results in the array
// [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums that may
// contain duplicates, return the minimum element
// of this array.

// You must decrease the overall operation steps 
// as much as possible.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int low = 0,high = nums.size()-1,mid;
        while(low <= high){
            mid = low + (high - low)/2;
            // left part sorted
            if(nums[mid] == nums[low] && nums[mid] == nums[high]) {
                ans = min(ans,nums[mid]);
                low++,high--;
            }
              // handling dublicate when we unable to identify which part is sorted
            else if(nums[low] <= nums[mid]){
                ans = min(ans,nums[low]);
                ans = min(ans,nums[high]);
                low = mid + 1;
            }
            
              // right part sorted
            else {
                ans = min(ans,nums[low]);
                ans = min(ans,nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
