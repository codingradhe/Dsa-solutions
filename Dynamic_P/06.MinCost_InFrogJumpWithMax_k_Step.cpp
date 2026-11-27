// Minimal Cost of Jumps
// Solved
// You are given an array arr[] of height of n stones and an integer k, where arr[i] represents
// the height of the i-th stone. You start at index 0 and want to reach the last stone (index n-1). 
// From any index i, you can jump to any index j such that i < j ≤ i+k. The cost of jumping from stone
// i to stone j is abs(arr[i] − arr[j]). Find the minimum total cost required to reach the last stone.



class Solution {
  private:
 // ❤️🤣🤣🤣  recursive solution
    // int findmin(int idx,int k ,vector<int> &arr){
    //     if(idx == 0) return 0;
    //     int mini = INT_MAX;
    //     for(int i = 1; i <= k; i++){
    //         if(idx - i >= 0) {
    //             int x = findmin(idx - i,k , arr);
    //             int curr = x + abs(arr[idx] - arr[idx - i]);
    //             mini = min(mini,curr);
    //         }
    //     }
    //     return mini;
    // }
// 🙌🙌🙌🙌🙌🙌 dp array wiht recursive solution
    // int findmin(int idx,int k ,vector<int> &arr,vector<int> &dp){
    //     if(dp[idx] != -1) return dp[idx];
    //     int mini = INT_MAX;
    //     for(int i = 1; i <= k; i++){
    //         if(idx - i >= 0) {
    //             int x = findmin(idx - i,k , arr ,dp);
    //             int curr = x + abs(arr[idx] - arr[idx - i]);
    //             mini = min(mini,curr);
    //         }
    //     }
    //     return dp[idx] = mini;
    // }
  public:
    // int minimizeCost(int k, vector<int>& arr) {
    //     int n =arr.size();
    //     vector<int>dp(n , -1);
    //     dp[0] = 0;
    //     return findmin(n - 1 , k ,arr,dp);
    // }
//🙌🙌🙌🙌🙌🙌  dp solution wiht dp array
    // int minimizeCost(int k, vector<int> &arr) {
    //   int n = arr.size();
    //   vector<int> dp(n, -1);
    //   dp[0] = 0;
    //   for (int i = 1; i < n; i++) {
    //     int mini = INT_MAX;
    //     for (int j = 1; j <= k; j++) {
    //       if (i - j >= 0) {
    //         int curr = dp[i - j] + abs(arr[i] - arr[i - j]);

    //         mini = min(mini, curr);
    //       }
    //     }
    //     dp[i] = mini;
    //   }

    //   return dp[n - 1];
    // }
// best approach with space optimization ❤️💕💕💕💕💕💕
    int minimizeCost(int k, vector<int> &arr) {
      int n = arr.size();

      vector<int> dp(k + 1, 0);

      for (int i = 1; i < n; i++) {
        int mini = INT_MAX;

        for (int j = 1; j <= k; j++) {
          if (i - j >= 0) {
            int curr = dp[(i - j) % (k + 1)] + abs(arr[i] - arr[i - j]);

            mini = min(mini, curr);
          }
        }

        dp[i % (k + 1)] = mini;
      }

      return dp[(n - 1) % (k + 1)];
    }
};
