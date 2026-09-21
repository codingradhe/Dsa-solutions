// 34. Find First and Last Position of Element in Sorted Array
// Medium
// Given an array of integers nums sorted in non-decreasing
//   order, find the starting and ending position of a given
// target value.
// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0,high = nums.size() -1,mid;
        int idx = -1;
        vector<int>ans = {-1,-1};
      // find any occurance of target element
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid] == target) {
                idx = mid;
                break;
            }
            else if(nums[mid] > target) high = mid -1;
            else low = mid + 1;
        }
        if(idx == -1) return ans;
        low = 0,high = idx;
      // find first occurance of target element -->> take low = mid to prevent 
      // forget first occurance of element
        while(low < high){
            mid = low + (high - low )/2;
            if(nums[mid] == target) high = mid;
            else low = mid + 1;
        }
        ans[0] = low;
        low = idx,high = nums.size()-1;
      // find last occurance of element so take mid = low +(high - low + 1)/2
      // to prevent form creating infinite loop
        while(low < high){
            mid = low + (high - low + 1)/2;
            if(nums[mid] == target) low = mid;
            else high = mid - 1;
        }
        ans[1] = low ;
        return ans;;
    }
};

