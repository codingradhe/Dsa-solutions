// 410. Split Array Largest Sum
// Hard
// Given an integer array nums and an integer k
// , split nums into k non-empty subarrays 
// such that the largest sum of any subarray is
// minimized.

// Return the minimized largest sum of the split .

// A subarray is a contiguous part of the array.
// ♥️♥️♥️🖊️ approach --
  // 1. set min to max element in array so that we can spilit min one length as subarray to each element in array
   // 2. set high to sum of all element so it can be a subarray itself if spilit is 1.
   // perform binary search to minimise max sum 
 // use  linear traversal to count spilit number when max sum of subarry is equal to mid. 
class Solution {
public:
    int countspilit(vector<int>& nums, int mid){
        int count = 1;
        int sum = 0;
        for(int i = 0;i < nums.size(); i++){
            if(sum + nums[i] > mid){
                count++;
                sum = 0;
            }
            sum += nums[i];
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size(),high = 0;
        int mid ,low = *max_element(nums.begin(),nums.end());
        for(int i = 0;i < n; i++){
            high += nums[i];
        }
        while(low <= high){
            mid = low + (high - low) / 2;
            int spilit = countspilit(nums,mid);
            if(spilit > k){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return low;
    }
};
