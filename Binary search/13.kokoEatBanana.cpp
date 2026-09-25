// 875. Koko Eating Bananas
// Medium
// Koko loves to eat bananas. There are n piles of
// bananas, the ith pile has piles[i] bananas. 
//   The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating 
//   speed of k. Each hour, she chooses some pile
// of bananas and eats k bananas from that pile. 
//   If the pile has less than k bananas, she 
//   eats all of them instead and will not eat any
// more bananas during this hour.

// Koko likes to eat slowly but still wants to finish
// eating all the bananas before the guards return.

// Return the minimum integer k such that she 
// can eat all the bananas within h hours.
// 🎊🎊♥️ idea -- > sort given array and perform binary search
?// to find out min speed to eat all banana in given hour  
class Solution {
public:
    long long timetaken(vector<int> v,int banana){
        long long time = 0;
        for(auto it:v){
            time += ((it + banana -1)/banana);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int n = nums.size(); 
        sort(nums.begin(),nums.end());
        int low = 1, high = nums[n-1],mid;
        int ans = INT_MAX;
        while(low <= high){
            mid = low + (high - low)/2;
            long long time = timetaken(nums,mid);
            if(time <= h) {
                ans = min(ans,mid);
                high = mid -1;
            }
            else low = mid + 1; 
        }
        return ans;
    }
};

