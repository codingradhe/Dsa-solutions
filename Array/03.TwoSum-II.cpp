// 167. Two Sum II - Input Array Is Sorted
// Medium
// You are given a 1-indexed array of integers
// numbers that is already sorted in non-decreasing
//   order.
// Find two numbers such that they add up to a specific
// target number. Let these two numbers be 
// numbers[index1] and numbers[index2] where 
//   1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers index1
// and index2 as an integer array [index1, index2] of length 2.

// The tests are generated such that there is 
// exactly one solution. You may not use the same
// element twice.

// Your solution must use only constant extra space.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;;
        while(left < right){
            int x = nums[left] + nums[right];
            if(x == target) {
                return {left + 1,right + 1};
            }
            else if(x > target) right--;
            else left++;
        }
        return {};
    }
};
