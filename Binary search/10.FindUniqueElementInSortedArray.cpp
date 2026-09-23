// 540. Single Element in a Sorted Array
// Medium
// You are given a sorted array consisting
// of only integers where every element appears
// exactly twice, except for one element 
// which appears exactly once.

// Return the single element that appears 
// only once.

// Your solution must run in O(log n) 
// time and O(1) space.
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans;
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        int low = 1,high = nums.size()-2,mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                ans = nums[mid];
                break;
            }
            else if(mid % 2 == 0){
                if(nums[mid] == nums[mid+1]) low = mid + 2;
                else high  = mid - 1;
            }
            else {
                if(nums[mid] == nums[mid+1]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return ans;
    }
};
