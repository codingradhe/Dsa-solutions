// 1283. Find the Smallest Divisor Given a Threshold
// Medium
// Given an array of integers nums and an integer threshold
// , we will choose a positive integer divisor, 
// divide all the array by it, and sum the 
// division's result. Find the smallest divisor such
//   that the result mentioned above is less than or
// equal to threshold.

// Each result of the division is rounded to the nearest
// integer greater than or equal to that element. 
//   (For example: 7/3 = 3 and 10/2 = 5).

// The test cases are generated so that there will be an
// answer.
// ♥️♥️♥️🖊️ approach -->> 
// for binary search -- set low = 1,and high can be max to max element to array because it can devide all element in one time
// perform binary seach 
// for count total diviser perform binary search
// for count total travers simple linear and devide and count
class Solution {
public:
    long long findsum(vector<int>& nums, int mid){
        long long ans = 0;
        for(int i = 0;i < nums.size() ; i++){
            ans += (nums[i] + mid - 1)/mid;
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1,mid, ans;
        int high = *max_element(nums.begin(),nums.end());
        while(low <= high){
            mid = low + (high - low)/2;
            long long sum = findsum(nums,mid);
            if(sum <= threshold) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};



