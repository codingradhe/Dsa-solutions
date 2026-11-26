// 198. House Robber
// Solved
// Medium


// You are a professional robber planning to rob houses along a street. Each house has
// a certain amount of money stashed, the only constraint stopping you from robbing each of 
// them is that adjacent houses have security systems connected and it will automatically
// contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the
//   maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0] , nums[1]);
// 💕💕❤️❤️ using dp array 
        // vector<int> dp(n , 0);
        // int pre = nums[0], spre = 0;
        // dp[0] = nums[0];
        // dp[1] = nums[1];
        // dp[2] = nums[0] + nums[2];
        // for(int i = 3; i < n; i++){
        //     dp[i] = max(dp[i - 2] , dp[i - 3]) + nums[i];
        // }
        // return max(dp[n - 1] , dp[n - 2]);
  // 😘😘😘😘 memorization 
        int pre = nums[2] + nums[0] , spre = nums[1] , tpre = nums[0];
        for(int i = 3; i < n ; i++){
            int curr = max(spre , tpre) + nums[i];
            tpre = spre ;
            spre = pre ;
            pre = curr;
        }
        return max(pre , spre);
    }
};
