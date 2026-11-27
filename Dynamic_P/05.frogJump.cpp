// Frog Jump
// Solved

// Given an integer array height[] where height[i] represents the height of the i-th stair, a 
//   frog starts from the first stair and wants to reach the last stair.

// From any stair i, the frog has two options: it can either jump to the (i+1)th stair
// or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs.

// Determine the minimum total cost required for the frog to reach the last stair.

class Solution {
// ❤️🤣🤣🤣💕 recursive solution
    // int findmin(int idx , vector<int> &dp ,vector<int> &v){
    //     if(dp[idx] != - 1) return dp[idx];
    //     int left = findmin(idx - 1,dp ,v) + abs(v[idx] - v[idx - 1]);
    //     int right = INT_MAX;
    //     if(idx >= 2 ) right = findmin(idx - 2,dp ,v) + abs(v[idx] - v[idx - 2]);
    //     return dp[idx] =  min(left , right);
    // }
  public:
    // int minCost(vector<int>& v) {
    //     int n = v.size();
    //     vector<int> dp(n , -1);
    //     dp[0] = 0;
    //     dp[1] = abs(v[0] - v[1]);
    //     int ans = findmin(n - 1, dp ,v);
    //     return ans;
    // }

/// 🙌👌 suing dp array
    int minCost(vector<int>& v) {
        // int n = v.size();
        // vector<int> dp(n , -1);
        // dp[0] = 0;
        // dp[1] = abs(v[0] - v[1]);
        // for(int i = 2; i < n; i++){
        //     int left = dp[i - 1] + abs(v[i] - v[i-1]);
        //     int right = dp[i - 2] + abs(v[i] - v[i - 2]);
        //     dp[i] = min(left , right);
        // }
        // return dp[n -1];
    /// 🙌👌 best approach
        int n = v.size();
        if(n == 1) return 0;
        int spre = 0;
        int pre  = abs(v[0] - v[1]);
        for(int i = 2; i < n; i++){
            int left = pre + abs(v[i] - v[i-1]);
            int right = spre + abs(v[i] - v[i - 2]);
            spre = pre;
            pre = min(left , right);
        }
        return pre;
    }
};



